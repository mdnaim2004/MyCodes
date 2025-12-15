#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        int total_rooms = 0;
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            total_rooms += (a + 1) / 2;
        }
        cout << total_rooms << endl;
    }
    return 0;
}
