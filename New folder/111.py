# keyboard_recorder_onecol.py
import pandas as pd
import numpy as np
import time
from pynput import keyboard
from pynput.keyboard import Key, KeyCode
from scipy.stats import entropy, skew, kurtosis
from collections import Counter, defaultdict
import json
import os
from datetime import datetime
import math

# ========================
# --- CONFIGURATION ---
# ========================
CONFIG = {
    "burst_threshold": 0.1,        # seconds
    "pause_threshold": 1.0,        # seconds
    "gap_exclusion_threshold": 5.0,   # 5 second er besi rest hole count hobbe na.
    "micro_pause_min": 0.5,        # micro-pause lower bound
    "micro_pause_max": 1.0,        # micro-pause upper bound
    "adaptive_event_window": 10,
    "alert_pause": 3.0,
    "user_id": "user001",
    "session_id": "sessionA",
    "condition": "control",
    "stress_level": 0.0,
    "session_number": 1,
    "device_type": "laptop",
    "environment": "home",

    "start_stress": None,
    "end_stress": None,
    "avg_stress": None,
    "final_condition": None,

    
    # per-key top N for per-key stats
    "top_keys_n": 5,
    "top_bigrams_n": 10,
    "chunk_size_presses": 50,  # for session segmentation
    "output_file": "keyboard_all_onecol.csv"
}

# ========================
# --- MAIN STORAGE ---
# ========================
key_event_log = []
key_press_map = {}
last_release_time = None

# Modifier key set (robust)
MOD_KEYS = {
    Key.shift, getattr(Key, "shift_l", None), getattr(Key, "shift_r", None),
    Key.ctrl, getattr(Key, "ctrl_l", None), getattr(Key, "ctrl_r", None),
    Key.alt, getattr(Key, "alt_l", None), getattr(Key, "alt_r", None),
    getattr(Key, "cmd", None), getattr(Key, "cmd_l", None), getattr(Key, "cmd_r", None),
}
MOD_KEYS = {k for k in MOD_KEYS if k is not None}

# ========================
# --- HELPER FUNCTIONS ---
# ========================
def key_to_str(k):
    if isinstance(k, KeyCode):
        return (k.char or "").lower() if k.char else ""
    if isinstance(k, Key):
        return k.name.lower()
    return str(k).split(".")[-1].lower()

def is_modifier_key(k):
    if k is None:
        return False
    try:
        if isinstance(k, Key):
            return k in MOD_KEYS
    except Exception:
        pass
    try:
        ks = (k.name.lower() if isinstance(k, Key) else str(k).lower())
        return ks in {"shift", "shift_l", "shift_r", "ctrl", "ctrl_l", "ctrl_r", "alt", "alt_l", "alt_r", "cmd", "cmd_l", "cmd_r"}
    except Exception:
        return False

def hand_mapping(key):
    left = set("qwertasdfgzxcvb")
    right = set("yuiophjklnm")
    if key in left:
        return "left"
    elif key in right:
        return "right"
    else:
        return "other"

def row_mapping(key):
    home = set("asdfghjkl")
    top = set("qwertyuiop")
    bottom = set("zxcvbnm")
    if key in home:
        return "home"
    elif key in top:
        return "top"
    elif key in bottom:
        return "bottom"
    else:
        return "other"

def make_py(obj):
    """Convert numpy types to python native for JSON serialisation"""
    if isinstance(obj, (np.floating, float)):
        return float(obj)
    if isinstance(obj, (np.integer, int)):
        return int(obj)
    if isinstance(obj, np.ndarray):
        return obj.tolist()
    return obj

# Simple QWERTY coordinates (approx) for travel distance estimation
_QWERTY_POS = {
    # row 1
    **{c: (i, 0) for i, c in enumerate("qwertyuiop")},
    # row 2
    **{c: (i + 0.5, 1) for i, c in enumerate("asdfghjkl")},
    # row 3
    **{c: (i + 1.0, 2) for i, c in enumerate("zxcvbnm")},
}

def key_travel_distance(a, b):
    if not a or not b:
        return 0.0
    a, b = a.lower(), b.lower()
    pa = _QWERTY_POS.get(a)
    pb = _QWERTY_POS.get(b)
    if pa and pb:
        return math.hypot(pa[0] - pb[0], pa[1] - pb[1])
    return 0.0

# ========================
# --- LISTENERS ---
# ========================
def on_press(key):
    global last_release_time
    timestamp = time.time()
    key_str = key_to_str(key) or str(key).split(".")[-1].lower()
    
    # --- গ্যাপ এক্সক্লুশন লজিক যোগ করা হলো (লাইন ১৭৮-এর কাছাকাছি) ---
    flight_time = None
    GAP_THRESHOLD = CONFIG.get("gap_exclusion_threshold", 5.0)

    if last_release_time is not None:
        gap_duration = timestamp - last_release_time
        
        if gap_duration <= GAP_THRESHOLD:
            # যদি গ্যাপ থ্রেশহোল্ডের মধ্যে থাকে, তবেই flight_time গণনা হবে
            flight_time = gap_duration
        else:
            # গ্যাপ বেশি হলে, flight_time None থাকবে
            print(f"⚠️ Long gap detected: {gap_duration:.2f}s (>{GAP_THRESHOLD}s). Flight time excluded.")
            flight_time = None
    is_mod = is_modifier_key(key) or is_modifier_key(key_str)
    is_back = (key == Key.backspace)

    if key not in key_press_map:
        key_press_map[key] = timestamp
        key_event_log.append({
            "user_id": CONFIG["user_id"],
            "session_id": CONFIG["session_id"],
            "timestamp": timestamp,
            "event": "press",
            "key": key_str,
            "raw_key": repr(key),
            "is_modifier": is_mod,
            "is_backspace": is_back,
            "key_hold_time": None,
            "flight_time": flight_time
        })

def on_release(key):
    global last_release_time
    timestamp = time.time()
    key_str = key_to_str(key) or str(key).split(".")[-1].lower()
    is_mod = is_modifier_key(key) or is_modifier_key(key_str)
    is_back = (key == Key.backspace)
    hold_time = None

    if key in key_press_map:
        press_time = key_press_map.pop(key)
        hold_time = timestamp - press_time

    key_event_log.append({
        "user_id": CONFIG["user_id"],
        "session_id": CONFIG["session_id"],
        "timestamp": timestamp,
        "event": "release",
        "key": key_str,
        "raw_key": repr(key),
        "is_modifier": is_mod,
        "is_backspace": is_back,
        "key_hold_time": hold_time,
        "flight_time": None
    })

    last_release_time = timestamp
    if key == Key.esc:
        print("\n🛑 ESC pressed — stopping recording...")
        return False

# ========================
# --- FEATURE ENGINEERING (with 15 extra) ---
# ========================
def compute_features(df):
    # === basic timestamp sanitise ===
    df["timestamp"] = pd.to_numeric(df.get("timestamp", pd.Series()), errors="coerce").astype(float)
    df = df.dropna(subset=["timestamp"]).sort_values("timestamp").reset_index(drop=True)

    if df.empty:
        empty_features = {"total_keys": 0}
        fatigue = {"fatigue_score": 0}
        return empty_features, fatigue, {}, {}, [], {}, [], []

    # Separate press/release and character presses (exclude modifiers/backspace)
    df_press = df[df["event"] == "press"].copy()
    df_release = df[(df["event"] == "release") & (df["key_hold_time"].notna())].copy()
    df_press_char = df_press[(~df_press["is_modifier"]) & (~df_press["is_backspace"])].copy()

    # IKI count
    df_press_char["inter_key_interval"] = df_press_char["timestamp"].diff()

    GAP_THRESHOLD = CONFIG.get("gap_exclusion_threshold", 5.0)
    df_press_char.loc[df_press_char["inter_key_interval"] > GAP_THRESHOLD, "inter_key_interval"] = np.nan


    # ---------------- per-second functions (DEFINE FIRST) ----------------
    def per_second_burst(df_press_char):
        ts = df_press_char["timestamp"].astype(float).values
        if len(ts) < 2:
            return {}

        iki = np.diff(ts)
        burst = (iki < CONFIG["burst_threshold"])

        t0 = ts[0]
        sec = np.floor(ts[1:] - t0).astype(int)

        s = pd.Series(burst.astype(int), index=sec).groupby(level=0).sum()
        s = s.reindex(range(0, int(sec.max()) + 1), fill_value=0)
        return s.to_dict()

    def per_second_wpm(df_press_char):
        ts = df_press_char["timestamp"].astype(float).values
        if len(ts) == 0:
            return {}

        t0 = ts[0]
        sec = np.floor(ts - t0).astype(int)

        kps = pd.Series(1, index=sec).groupby(level=0).sum()
        kps = kps.reindex(range(0, int(sec.max()) + 1), fill_value=0)

        wpm = (kps * 60.0) / 5.0
        return wpm.to_dict()

    # ---------------- now CALL them ----------------
    burst_series = per_second_burst(df_press_char)
    wpm_series = per_second_wpm(df_press_char)

    # hand and row maping
    df_press_char["hand"] = df_press_char["key"].apply(hand_mapping)
    df_press_char["row"] = df_press_char["key"].apply(row_mapping)

    features = {}
    # ✅ per-second series features এ ঢুকিয়ে দিলাম
    features["burst_per_sec"] = burst_series
    features["wpm_per_sec"] = wpm_series

    total_presses = len(df_press_char)
    backspace_count = int(df_press[df_press["is_backspace"]].shape[0])


    # ----- BASIC METRICS -----

    features["total_keys"] = int(total_presses)
    features["total_backspaces"] = int(backspace_count)
    features["error_rate"] = (backspace_count / total_presses) if total_presses > 0 else 0.0
    features["accuracy"] = 1.0 - features["error_rate"]
    features["session_duration"] = float(max(df["timestamp"].max() - df["timestamp"].min(), 1e-6))
    features["WPM"] = float(((total_presses / 5.0) / (features["session_duration"] / 60.0)) if features["session_duration"] > 0 else 0.0)

    # ----- TEMPORAL DYNAMICS -----
    ikis = df_press_char["inter_key_interval"].dropna().values
    features["mean_iki"] = float(np.mean(ikis)) if len(ikis) > 0 else 0.0
    features["median_iki"] = float(np.median(ikis)) if len(ikis) > 0 else 0.0
    features["max_pause"] = float(np.max(ikis)) if len(ikis) > 0 else 0.0
    features["min_iki"] = float(np.min(ikis)) if len(ikis) > 0 else 0.0
    features["cv"] = float(np.std(ikis) / (np.mean(ikis) + 1e-6)) if len(ikis) > 0 else 0.0
    features["skewness"] = float(skew(ikis)) if len(ikis) > 2 else 0.0
    features["kurtosis"] = float(kurtosis(ikis)) if len(ikis) > 2 else 0.0
    features["consistency"] = float(np.std(ikis)) if len(ikis) > 5 else 0.0
    features["burst_count"] = int(np.sum(ikis < CONFIG["burst_threshold"])) if len(ikis) > 0 else 0
    features["pause_count"] = int(np.sum(ikis > CONFIG["pause_threshold"])) if len(ikis) > 0 else 0
    features["mean_dwell"] = float(df_release["key_hold_time"].mean()) if len(df_release) > 0 else 0.0
    flight_times = df_press_char["flight_time"].dropna()
    features["mean_flight_time"] = float(flight_times.mean()) if len(flight_times) > 0 else 0.0


    #Active time
    #-----------
    # active_time = float(np.sum(df_press_char["inter_key_interval"].dropna().values))
    # features["active_time"] = active_time
    # features["WPM_active"] = float(((total_presses / 5.0) / (active_time / 60.0)) if active_time > 0 else 0.0)


    # micro pauses
    if len(ikis) > 0:
        micro_pauses = ikis[(ikis > CONFIG["micro_pause_min"]) & (ikis < CONFIG["micro_pause_max"])]
        features["micro_pause_count"] = int(len(micro_pauses))
    else:
        features["micro_pause_count"] = 0

    # ----- FATIGUE (improved) -----
    ikis_eval = np.array([float(x) for x in ikis if np.isfinite(x) and x > 0.0]) if len(ikis) > 0 else np.array([])
    features["fatigue_start"] = 0.0
    features["fatigue_end"] = 0.0
    features["fatigue_change"] = 0.0
    features["fatigue_trend"] = 0.0
    features["fatigue_rolling_mean_start"] = 0.0
    features["fatigue_rolling_mean_end"] = 0.0
    fatigue = {"fatigue_score": 0, "burst_score": 0, "outlier_score": 0, "speed_variability": 0.0, "pause_ratio": 0.0}

    if ikis_eval.size >= 2:
        mean_iki = float(np.mean(ikis_eval))
        std_iki = float(np.std(ikis_eval))
        p_thresh = CONFIG.get("pause_threshold", 1.0)
        b_thresh = CONFIG.get("burst_threshold", 0.1)
        fatigue["fatigue_score"] = int(np.sum(ikis_eval > p_thresh))
        fatigue["burst_score"] = int(np.sum(ikis_eval < b_thresh))
        fatigue["outlier_score"] = int(np.sum(ikis_eval > (mean_iki + 3.0 * std_iki))) if std_iki > 1e-9 else 0
        fatigue["speed_variability"] = float(std_iki / (mean_iki + 1e-9))
        fatigue["pause_ratio"] = float(fatigue["fatigue_score"] / len(ikis_eval))
        # dynamic window
        data_len = len(ikis_eval)
        window_size = max(2, min(10, int(data_len * 0.2)))
        start_segment = ikis_eval[:window_size]
        end_segment = ikis_eval[-window_size:]
        features["fatigue_start"] = float(np.mean(start_segment))
        features["fatigue_end"] = float(np.mean(end_segment))
        features["fatigue_rolling_mean_start"] = features["fatigue_start"]
        features["fatigue_rolling_mean_end"] = features["fatigue_end"]
        features["fatigue_change"] = float(features["fatigue_end"] - features["fatigue_start"])
        features["fatigue_trend"] = features["fatigue_change"]

    # ----- BURST STREAK -----
    if len(ikis) > 0:
        burst = (ikis < CONFIG["burst_threshold"])
        if burst.any():
            idx = np.where(np.concatenate(([burst[0]], burst[1:] != burst[:-1], [True])))[0]
            run_lengths = np.diff(idx)
            features["max_burst_streak"] = int(run_lengths[::2].max()) if len(run_lengths) > 0 else 0
            # mean burst length
            burst_runs = run_lengths[::2] if len(run_lengths) > 0 else []
            features["mean_burst_length"] = float(np.mean(burst_runs)) if len(burst_runs) > 0 else 0.0
        else:
            features["max_burst_streak"] = 0
            features["mean_burst_length"] = 0.0
    else:
        features["max_burst_streak"] = 0
        features["mean_burst_length"] = 0.0

    # ----- LONGEST PAUSE -----
    if len(ikis) > 0:
        pause_idx = int(np.argmax(ikis))
        features["longest_pause_time"] = float(ikis[pause_idx])
        if (pause_idx + 1) < len(df_press_char):
            features["longest_pause_timestamp"] = float(df_press_char.iloc[pause_idx + 1]["timestamp"])
        else:
            features["longest_pause_timestamp"] = float(df_press_char.iloc[-1]["timestamp"])
    else:
        features["longest_pause_time"] = 0.0
        features["longest_pause_timestamp"] = 0.0

    # ----- HAND & ROW STATS -----
    features["left_hand_count"] = int((df_press_char["hand"] == "left").sum())
    features["right_hand_count"] = int((df_press_char["hand"] == "right").sum())
    features["other_hand_count"] = int((df_press_char["hand"] == "other").sum())
    features["home_row_count"] = int((df_press_char["row"] == "home").sum())
    features["top_row_count"] = int((df_press_char["row"] == "top").sum())
    features["bottom_row_count"] = int((df_press_char["row"] == "bottom").sum())
    features["other_row_count"] = int((df_press_char["row"] == "other").sum())
    features["left_right_ratio"] = float(features["left_hand_count"] / (features["right_hand_count"] + 1e-6))
    features["hand_balance_ratio"] = float(features["left_hand_count"] / (features["right_hand_count"] + 1e-6))
    features["home_row_efficiency"] = float(features["home_row_count"] / (total_presses + 1e-6))
    features["hold_time_variability"] = float(df_release["key_hold_time"].std()) if len(df_release) > 0 else 0.0

    # ----- ACTIVE/IDLE -----
    if len(df_press_char) > 1:
        active_duration = float(df_press_char["inter_key_interval"].dropna().sum())
    else:
        active_duration = 0.0
    idle_periods = ikis[ikis > CONFIG["pause_threshold"]] if len(ikis) > 0 else np.array([])
    features["active_typing_duration"] = float(active_duration)
    features["idle_duration"] = float(np.sum(idle_periods)) if len(idle_periods) > 0 else 0.0
    features["typing_efficiency"] = float(active_duration / (active_duration + features["idle_duration"] + 1e-6))
    features["burst_to_pause_ratio"] = float((features["burst_count"] + 1e-6) / (features["pause_count"] + 1e-6))
    features["avg_key_frequency"] = float(total_presses / (features["session_duration"] + 1e-6))

    # ----- ATTENTION METRICS -----
    long_idle_periods = ikis[ikis > CONFIG["pause_threshold"]]
    features["long_idle_count"] = int(len(long_idle_periods))
    features["long_idle_max"] = float(np.max(long_idle_periods)) if len(long_idle_periods) > 0 else 0.0
    features["attention_drop_ratio"] = float(np.mean(ikis[-10:]) / (np.mean(ikis[:10]) + 1e-6)) if len(ikis) > 20 else 0.0

    # ----- ACTIVE-MODE METRICS -----
    features["active_WPM"] = float(((len(df_press_char) / 5.0) / (active_duration / 60.0)) if active_duration > 0 else 0.0)
    active_backspaces = int(df_press[df_press["is_backspace"]].shape[0])
    features["active_error_rate"] = float(active_backspaces / len(df_press_char)) if len(df_press_char) > 0 else 0.0
    features["active_accuracy"] = float(1.0 - features["active_error_rate"])
    features["typing_efficiency_ratio"] = float(active_duration / (features["session_duration"] + 1e-6))

    # ----- ATTENTION DROP RATE -----
    if len(df_press_char) > 20:
        half = len(df_press_char) // 2
        first_half_iki = float(np.mean(df_press_char["inter_key_interval"].iloc[1:half].dropna())) if half > 1 else 0.0
        second_half_iki = float(np.mean(df_press_char["inter_key_interval"].iloc[half+1:].dropna())) if (len(df_press_char) - half) > 1 else 0.0
        if first_half_iki > 0:
            features["attention_drop_rate"] = float((second_half_iki - first_half_iki) / (first_half_iki + 1e-6))
        else:
            features["attention_drop_rate"] = 0.0
    else:
        features["attention_drop_rate"] = 0.0

    # ----- CONTEXT USAGE -----
    context_keys = ["space", "enter", "caps_lock", "tab", "up", "down", "left", "right"]
    context_usage = {k: int((df_press["key"] == k).sum()) for k in context_keys}
    features.update({f"{k}_count": v for k, v in context_usage.items()})

    # ----- MODIFIERS -----
    mods_press = df_press[df_press["is_modifier"]]
    mod_freq = mods_press["key"].value_counts().to_dict()
    mod_release = df[(df["event"] == "release") & (df["is_modifier"]) & (df["key_hold_time"].notna())]
    mod_hold_time = mod_release.groupby("key")["key_hold_time"].mean().to_dict()
    char_base = total_presses + 1e-6
    features["modifier_dependency_ratio"] = float(len(mods_press) / char_base)
    space_presses = int((df_press_char["key"] == "space").sum())
    features["space_usage_ratio"] = float(space_presses / char_base)

    # ----- ERROR BEHAVIOR -----
    df_press_only = df[df["event"] == "press"].reset_index(drop=True)
    back_press_idx = df_press_only.index[df_press_only["is_backspace"]].to_list()
    if len(back_press_idx) > 0:
        runs = []
        run_len = 1
        for i in range(1, len(back_press_idx)):
            if back_press_idx[i] == back_press_idx[i-1] + 1:
                run_len += 1
            else:
                runs.append(run_len)
                run_len = 1
        runs.append(run_len)
        features["error_streak_max"] = int(max(runs))
        features["sequential_backspaces"] = int(sum(r - 1 for r in runs))
    else:
        features["error_streak_max"] = 0
        features["sequential_backspaces"] = 0
    features["backspace_ratio"] = float(backspace_count / (total_presses + 1e-6))
    features["retype_rate"] = float(features["sequential_backspaces"] / (total_presses + 1e-6))

    # ----- Most common before backspace -----
    error_pairs = []
    bp_idx = df_press_only.index[df_press_only["is_backspace"]].to_list()
    for idx in bp_idx:
        if idx >= 1:
            prev_key = df_press_only.iloc[idx - 1]["key"]
            cur_key  = df_press_only.iloc[idx]["key"]
            error_pairs.append((prev_key, cur_key))
    error_pair_count = Counter(error_pairs).most_common(5)

    # ----- Cognitive & Switching -----
    repeat_keys = df_press_char["key"].value_counts()
    features["average_key_repeat_rate"] = float(np.mean(repeat_keys.values)) if len(repeat_keys) > 0 else 0.0
    unique_keys = int(df_press_char["key"].nunique())
    features["switching_rate"] = float(unique_keys / (total_presses + 1e-6))

    if len(ikis) > 5:
        rolling_std = pd.Series(ikis).rolling(window=5, min_periods=1).std()
        features["attention_fluctuation"] = float(np.mean(rolling_std))
    else:
        features["attention_fluctuation"] = 0.0

    if len(ikis) > 10:
        attention_slope = np.polyfit(range(len(ikis)), ikis, 1)[0]
        features["attention_trend_slope"] = float(attention_slope)
    else:
        features["attention_trend_slope"] = 0.0

    features["typing_stability_index"] = float(1 / (1 + np.std(ikis))) if len(ikis) > 0 else 0.0
    features["repeated_error_rate"] = float(features["error_streak_max"] / (total_presses + 1e-6))
    features["attention_variability"] = float(np.std(df_press_char["inter_key_interval"].dropna())) if len(df_press_char) > 1 else 0.0
    features["key_switching_frequency"] = float(len(df_press_char["key"].unique()) / (total_presses + 1e-6))

    # ----- N-GRAMS -----
    keys_seq = df_press_char["key"].tolist()
    ngrams = [tuple(keys_seq[i:i+3]) for i in range(len(keys_seq) - 2)] if len(keys_seq) > 2 else []
    ngram_patterns = Counter(ngrams).most_common(10)

    bigrams = [(keys_seq[i], keys_seq[i+1]) for i in range(len(keys_seq)-1)] if len(keys_seq) > 1 else []
    bigram_ikis = defaultdict(list)
    ikis_clean_for_bigrams = df_press_char["inter_key_interval"].dropna().values
    for i, bg in enumerate(bigrams[:len(ikis_clean_for_bigrams)]):
        bigram_ikis[bg].append(float(ikis_clean_for_bigrams[i]))
    bigram_stat = {str(bg): float(np.mean(lat)) if len(lat) > 0 else 0.0 for bg, lat in bigram_ikis.items()}
    top_bigram_stat = dict(sorted(bigram_stat.items(), key=lambda x: -x[1])[:5])

    rev_trigrams = [tuple(reversed(keys_seq[i:i+3])) for i in range(len(keys_seq) - 2)] if len(keys_seq) > 2 else []
    rev_ngram_patterns = Counter(rev_trigrams).most_common(3)

    # ----- Additional Explicit Features (modifier hold means etc.) -----
    mods_keys_series = mods_press["key"].astype(str).str.lower() if "key" in mods_press.columns else pd.Series(dtype=str)
    features["shift_count"] = int(mods_keys_series.str.contains("shift").sum()) if not mods_keys_series.empty else 0
    features["ctrl_count"]  = int(mods_keys_series.str.contains("ctrl").sum()) if not mods_keys_series.empty else 0
    features["alt_count"]   = int(mods_keys_series.str.contains("alt").sum()) if not mods_keys_series.empty else 0
    features["cmd_count"]   = int(mods_keys_series.str.contains("cmd|meta").sum()) if not mods_keys_series.empty else 0

    mod_hold_time = mod_release.groupby("key")["key_hold_time"].mean().to_dict() if len(mod_release) > 0 else {}
    features["shift_hold_mean"] = float(mod_hold_time.get("shift", 0.0) or 0.0)
    features["ctrl_hold_mean"]  = float(mod_hold_time.get("ctrl", 0.0) or 0.0)
    features["alt_hold_mean"]   = float(mod_hold_time.get("alt", 0.0) or 0.0)
    features["cmd_hold_mean"]   = float(mod_hold_time.get("cmd", 0.0) or 0.0)

    if len(ikis) > 0:
        features["iki_p10"] = float(np.percentile(ikis, 10))
        features["iki_p25"] = float(np.percentile(ikis, 25))
        features["iki_p75"] = float(np.percentile(ikis, 75))
        features["iki_p90"] = float(np.percentile(ikis, 90))
        try:
            hist, _ = np.histogram(ikis, bins=min(20, max(3, len(ikis)//2)), density=True)
            hist = hist + 1e-12
            features["ikis_entropy"] = float(entropy(hist))
        except Exception:
            features["ikis_entropy"] = 0.0
    else:
        features["iki_p10"] = features["iki_p25"] = features["iki_p75"] = features["iki_p90"] = 0.0
        features["ikis_entropy"] = 0.0

    if len(df_release) > 0:
        features["dwell_median"] = float(pd.Series(df_release["key_hold_time"].dropna()).median())
        features["dwell_std"] = float(pd.Series(df_release["key_hold_time"].dropna()).std()) if df_release["key_hold_time"].dropna().size > 0 else 0.0
    else:
        features["dwell_median"] = 0.0
        features["dwell_std"] = 0.0

    flight_vals = df_press["flight_time"].dropna().astype(float).values if "flight_time" in df_press.columns else np.array([])
    if flight_vals.size > 0:
        features["flight_median"] = float(np.median(flight_vals))
        features["flight_std"] = float(np.std(flight_vals))
    else:
        features["flight_median"] = 0.0
        features["flight_std"] = 0.0

    features["unique_ngrams_count"] = int(len(set(ngrams)))
    features["top_ngram_freq"] = int(ngram_patterns[0][1]) if isinstance(ngram_patterns, list) and len(ngram_patterns) > 0 else 0
    try:
        if isinstance(top_bigram_stat, dict) and len(top_bigram_stat) > 0:
            features["bigram_top_mean_latency"] = float(list(top_bigram_stat.values())[0])
        else:
            features["bigram_top_mean_latency"] = 0.0
    except Exception:
        features["bigram_top_mean_latency"] = 0.0

    session_minutes = features["session_duration"] / 60.0 if features.get("session_duration", 0.0) > 0 else 1e-6
    features["bursts_per_minute"] = float(features.get("burst_count", 0) / session_minutes)
    denom = max(features.get("WPM", 0.0), 1e-6)
    features["active_to_overall_wpm_ratio"] = float(features.get("active_WPM", 0.0) / denom)

    # ========================
    # --- 15 EXTRA FEATURES ---
    # 1) Per-key timing stats (top N)
    # ========================
    top_n = CONFIG.get("top_keys_n", 5)
    key_stats = {}
    if total_presses > 0:
        top_keys = [k for k, _ in df_press_char["key"].value_counts().head(top_n).items()]
        for k in top_keys:
            # mean hold time directly from release events
            mean_hold = float(
                df_release[df_release["key"] == k]["key_hold_time"].mean()
            ) if len(df_release) > 0 else 0.0

            # mean inter-key interval when that key appears
            positions = df_press_char.reset_index(drop=True)
            idxs = positions.index[positions["key"] == k].tolist()

            iki_list = []
            for pos in idxs:
                if pos > 0:
                    val = positions.iloc[pos]["inter_key_interval"]
                    if pd.notna(val):
                        iki_list.append(float(val))


            key_stats[f"key_{k}_mean_hold"] = float(mean_hold or 0.0)
            key_stats[f"key_{k}_mean_iki"] = float(np.mean(iki_list)) if len(iki_list) > 0 else 0.0


    # attach
    features.update(key_stats)

    # 2) Per-bigram frequency top-K (already have bigram_stat) -> flatten top K
    bigram_items = sorted(bigram_stat.items(), key=lambda x: -x[1])[:CONFIG.get("top_bigrams_n", 10)]
    for i, (bg, lat) in enumerate(bigram_items):
        features[f"bigram_top_{i+1}"] = bg
        features[f"bigram_top_{i+1}_latency"] = float(lat)

    # 3) Key-transition entropy / Markov-like features
    transition_counts = Counter(bigrams)
    total_trans = sum(transition_counts.values()) if transition_counts else 1
    trans_probs = np.array(list(transition_counts.values())) / float(total_trans)
    features["transition_entropy"] = float(entropy(trans_probs)) if len(trans_probs)>0 else 0.0

    # 4) Pause-context features (pause before/after space)
    pauses_after_space = 0
    pauses_before_space = 0
    if len(ikis) > 0 and len(df_press_char)>1:
        # iterate pairs in df_press (press-only chars)
        for i in range(1, len(df_press_char)):
            prev_key = df_press_char.iloc[i-1]["key"]
            iki_val = df_press_char.iloc[i]["inter_key_interval"]
            if pd.notna(iki_val) and iki_val > CONFIG["pause_threshold"]:
                if prev_key == "space":
                    pauses_after_space += 1
                if df_press_char.iloc[i]["key"] == "space":
                    pauses_before_space += 1
    features["pauses_after_space"] = int(pauses_after_space)
    features["pauses_before_space"] = int(pauses_before_space)

    # 5) Time-of-day features
    session_start_ts = float(df["timestamp"].min())
    dt = datetime.fromtimestamp(session_start_ts)
    features["session_start_hour"] = dt.hour
    features["session_start_weekday"] = dt.weekday()
    features["session_is_night"] = int(dt.hour < 6 or dt.hour >= 22)

    # 6) Rolling window stats (rolling mean IKI window=5)
    if len(ikis) > 0:
        roll_mean = pd.Series(ikis).rolling(window=5, min_periods=1).mean().fillna(method="ffill").astype(float)
        features["rolling_mean_iki_last"] = float(roll_mean.iloc[-1])
        # slope of rolling mean across whole session (linear fit)
        try:
            slope = np.polyfit(range(len(roll_mean)), roll_mean, 1)[0]
            features["rolling_mean_iki_slope"] = float(slope)
        except Exception:
            features["rolling_mean_iki_slope"] = 0.0
    else:
        features["rolling_mean_iki_last"] = 0.0
        features["rolling_mean_iki_slope"] = 0.0

    # 7) Autocorrelation features (lag 1)
    if len(ikis) > 1:
        iki_series = pd.Series(ikis)
        features["iki_autocorr_lag1"] = float(iki_series.autocorr(lag=1))
    else:
        features["iki_autocorr_lag1"] = 0.0

    # 8) Key-sequence entropy (character frequency)
    if len(keys_seq) > 0:
        counts = np.array(list(Counter(keys_seq).values()))
        probs = counts / counts.sum()
        features["char_sequence_entropy"] = float(entropy(probs))
    else:
        features["char_sequence_entropy"] = 0.0

    # 9) Error recovery metrics: time to next non-backspace after backspace
    recovery_times = []
    # index in press-only df
    press_idx_map = df_press_only.reset_index(drop=True)
    for i in range(len(press_idx_map)):
        if press_idx_map.iloc[i]["is_backspace"]:
            # find next non-backspace press
            j = i+1
            while j < len(press_idx_map) and press_idx_map.iloc[j]["is_backspace"]:
                j += 1
            if j < len(press_idx_map):
                t_back = press_idx_map.iloc[i]["timestamp"]
                t_next = press_idx_map.iloc[j]["timestamp"]
                recovery_times.append(float(t_next - t_back))
    features["error_recovery_mean"] = float(np.mean(recovery_times)) if len(recovery_times)>0 else 0.0
    features["error_recovery_count"] = int(len(recovery_times))

    # 10) Burst segmentation features (mean burst inter-arrival)
    if len(ikis) > 0:
        bursts_idx = np.where(ikis < CONFIG["burst_threshold"])[0]
        if len(bursts_idx) > 0:
            # compute distances between starts of consecutive bursts
            starts = []
            prev = None
            i = 0
            while i < len(ikis):
                if ikis[i] < CONFIG["burst_threshold"]:
                    starts.append(i)
                    # skip to end of this burst
                    j = i+1
                    while j < len(ikis) and ikis[j] < CONFIG["burst_threshold"]:
                        j += 1
                    i = j
                else:
                    i += 1
            if len(starts) > 1:
                deltas = np.diff(starts)
                features["burst_interarrival_mean"] = float(np.mean(deltas))
            else:
                features["burst_interarrival_mean"] = 0.0
        else:
            features["burst_interarrival_mean"] = 0.0
    else:
        features["burst_interarrival_mean"] = 0.0

    # 11) Normalized/session zscores for a couple of main features
    # (since we don't have historical baseline, we normalise w.r.t session mean/std)
    def zscore(x):
        try:
            arr = np.array(x)
            return float((arr[-1] - arr.mean()) / (arr.std() + 1e-9))
        except Exception:
            return 0.0
    # example: zscore of last iki relative to all ikis
    if len(ikis) > 0:
        features["last_iki_zscore"] = zscore(ikis)
    else:
        features["last_iki_zscore"] = 0.0

    # 12) Keyboard travel distance approximations (avg per transition)
    travel_list = []
    for i in range(1, len(keys_seq)):
        travel_list.append(key_travel_distance(keys_seq[i-1], keys_seq[i]))
    features["avg_travel_distance"] = float(np.mean(travel_list)) if len(travel_list)>0 else 0.0
    features["sum_travel_distance"] = float(np.sum(travel_list)) if len(travel_list)>0 else 0.0

    # 13) Wearable sync summary (if any)
    wearable = CONFIG.get("wearable")
    if wearable and isinstance(wearable, list) and len(wearable)>0:
        try:
            hrs = [w.get("hr") for w in wearable if w.get("hr") is not None]
            features["wearable_hr_mean"] = float(np.mean(hrs)) if len(hrs)>0 else None
            features["wearable_hrv_mean"] = float(np.mean([w.get("hrv") for w in wearable if w.get("hrv") is not None])) if any(w.get("hrv") is not None for w in wearable) else None
        except Exception:
            features["wearable_hr_mean"] = None
            features["wearable_hrv_mean"] = None
    else:
        features["wearable_hr_mean"] = None
        features["wearable_hrv_mean"] = None

    # 14) Session segmentation & chunk-level counts
    chunk_size = CONFIG.get("chunk_size_presses", 50)
    n_chunks = math.ceil(total_presses / float(chunk_size)) if chunk_size>0 else 1
    features["session_chunk_count"] = int(n_chunks)
    features["session_chunk_size"] = int(chunk_size)

    # 15) Outlier flags
    if len(ikis) > 0:
        features["num_large_outliers"] = int(np.sum(ikis > (np.mean(ikis) + 3*np.std(ikis)))) if np.std(ikis)>0 else 0
        features["has_large_outlier"] = int(features["num_large_outliers"] > 0)
    else:
        features["num_large_outliers"] = 0
        features["has_large_outlier"] = 0

    # finalize ngram/bigram/rev lists for return
    ngram_patterns_final = ngram_patterns
    bigram_stat_final = bigram_stat
    error_pairs_final = error_pair_count
    rev_ngram_patterns_final = rev_ngram_patterns

    # Convert numpy types in features to python native
    features = {k: make_py(v) for k, v in features.items()}
    fatigue = {k: make_py(v) for k, v in fatigue.items()}

    return (
        features, fatigue, mod_freq, mod_hold_time, ngram_patterns_final,
        top_bigram_stat, error_pairs_final, rev_ngram_patterns_final
    )

# ========================
# --- SAVE single-column JSON CSV ---
# ========================
def save_all_as_single_json_col(meta_info, features, fatigue, mod_freq, mod_hold_time,
                                ngram_patterns, bigram_stat, error_pairs, rev_ngram_patterns,
                                user_report="", file_path=None):
    if file_path is None:
        file_path = CONFIG.get("output_file", "keyboard_all_onecol.csv")
    os.makedirs(os.path.dirname(file_path) or ".", exist_ok=True)
    combined = {**meta_info, **features, **fatigue,
                "mod_freq": mod_freq, "mod_hold_time": mod_hold_time,
                "ngram_patterns": ngram_patterns, "bigram_latency_stats": bigram_stat,
                "common_error_pairs": error_pairs, "reverse_ngrams": rev_ngram_patterns,
                "user_report": user_report}
    # Ensure everything JSON serialisable: convert numpy types etc.
    def safe_convert(o):
        if isinstance(o, (np.integer, np.int64, int)):
            return int(o)
        if isinstance(o, (np.floating, np.float64, float)):
            return float(o)
        if isinstance(o, np.ndarray):
            return o.tolist()
        if isinstance(o, dict):
            return {str(k): safe_convert(v) for k, v in o.items()}
        if isinstance(o, list):
            return [safe_convert(x) for x in o]
        return o
    combined_safe = safe_convert(combined)
    row = combined_safe
    df = pd.DataFrame([row])

    if not os.path.exists(file_path):
        df.to_csv(file_path, index=False)
    else:
        df.to_csv(file_path, mode='a', header=(not os.path.exists(file_path)), index=False)
    print(f"\n✅ Saved session data as ORGANIZED CSV at '{file_path}'\n")

# ========================
# --- MAIN ---
# ========================
def main():
    try:
        CONFIG["user_id"] = input("Enter User ID: ").strip() or CONFIG["user_id"]
        CONFIG["session_id"] = input("Enter Session ID: ").strip() or CONFIG["session_id"]
        CONFIG["device_type"] = input("Device type (laptop/desktop): ").strip() or CONFIG["device_type"]
        CONFIG["environment"] = input("Enter environment (quiet/noisy/lab/home): ").strip() or CONFIG["environment"]
        try:
            start_stress = int(input("Enter smartwatch stress score (1-100) at start: "))
        except Exception:
            start_stress = 50
        CONFIG["stress_level"] = start_stress
        CONFIG["start_stress"] = start_stress

        if 1 <= start_stress <= 29:
            CONFIG["condition"] = "Relaxed"
        elif 30 <= start_stress <= 59:
            CONFIG["condition"] = "Normal"
        elif 60 <= start_stress <= 79:
            CONFIG["condition"] = "Medium"
        elif 80 <= start_stress <= 100:
            CONFIG["condition"] = "High"
        else:
            CONFIG["condition"] = "Unknown"
    except Exception:
        pass

    end_condition = None
    end_stress_level = None

    meta_info = {
        "user_id": CONFIG["user_id"],
        "session_id": CONFIG["session_id"],
        "condition": CONFIG["condition"],
        "stress_level": CONFIG["stress_level"],
        "session_number": CONFIG["session_number"],
        "device_type": CONFIG["device_type"],
        "environment": CONFIG["environment"],
        "date": time.strftime('%Y-%m-%d %H:%M:%S'),
        "time_of_day": time.strftime('%H:%M:%S'),
        "start_stress": CONFIG["start_stress"],
    }



    print("---------------------------------------------------------")
    print("⌨️ Keyboard Recording Started (Press ESC to stop)")
    print(f"User: {CONFIG['user_id']} | Session: {CONFIG['session_id']} | Condition: {CONFIG['condition']}")
    print("---------------------------------------------------------")

    try:
        with keyboard.Listener(on_press=on_press, on_release=on_release) as kl:
            kl.join()
    except Exception as e:
        print("❌ Keyboard listener error:", e)
        return

    print("\n🟢 Recording stopped — processing data...\n")

    if not key_event_log:
        print("❌ No data recorded.")
        return

    df = pd.DataFrame(key_event_log)
    (features, fatigue, mod_freq, mod_hold_time, ngram_patterns,
     bigram_stat, error_pairs, rev_ngram_patterns) = compute_features(df)

    # session end stress
    try:
        try:
            end_stress = int(input("Enter smartwatch stress score (1-100) at the end: "))
        except Exception:
            end_stress = CONFIG["stress_level"]

        end_stress_level = end_stress
        CONFIG["end_stress"] = end_stress

        avg_stress = int((CONFIG["start_stress"] + CONFIG["end_stress"]) / 2)
        CONFIG["avg_stress"] = avg_stress

        if 1 <= avg_stress <= 29:
            end_condition = "Relaxed"
        elif 30 <= avg_stress <= 59:
            end_condition = "Normal"
        elif 60 <= avg_stress <= 79:
            end_condition = "Medium"
        elif 80 <= avg_stress <= 100:
            end_condition = "High"
        else:
            end_condition = "Unknown"

        meta_info["end_condition"] = end_condition
        meta_info["end_stress_level"] = end_stress_level
        meta_info["end_stress"] = end_stress
        meta_info["avg_stress"] = avg_stress
        meta_info["final_condition"] = end_condition

        user_report = input("Session finished. Please rate your focus/mood (optional): ")

    except Exception:
        end_condition = CONFIG["condition"]
        end_stress_level = CONFIG["stress_level"]
        user_report = ""


    save_all_as_single_json_col(
        meta_info, features, fatigue, mod_freq, mod_hold_time, ngram_patterns,
        bigram_stat, error_pairs, rev_ngram_patterns, user_report,
        file_path=CONFIG.get("output_file")
    )

    # Print short summary
    print("🧠 Feature Summary (sample):")
    sample_keys = ["total_keys", "WPM", "mean_iki", "median_iki", "fatigue_change", "num_large_outliers"]
    for k in sample_keys:
        print(f"  {k:<20}: {features.get(k)}")
    print("\n✅ Done. CSV appended with single line column. Open", CONFIG.get("output_file"))

if __name__ == "__main__":
    main()



    
                                                                                                                                                                                                                  