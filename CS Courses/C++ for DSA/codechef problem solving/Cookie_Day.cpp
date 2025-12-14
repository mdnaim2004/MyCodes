#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        long long ans = LLONG_MAX;

        for (int i = 0; i < N; i++) {
            long long A;
            cin >> A;

            if (A >= K) {
                ans = min(ans, A % K);
            }
        }

        if (ans == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
