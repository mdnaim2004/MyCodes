#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, D;
        cin >> N >> D;

        int A[N];   // normal array
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int currentGun = 0; // 0 = close, 1 = long
        int switches = 0;

        for (int i = 0; i < N; i++) {
            int requiredGun;

            if (A[i] <= D)
                requiredGun = 0;   // close gun
            else
                requiredGun = 1;   // long gun

            if (requiredGun != currentGun) {
                switches++;
                currentGun = requiredGun;
            }
        }

        cout << switches << endl;
    }

    return 0;
}
