#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        int n;
        cin >> n;

        int arr[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        int odd = 0;
        int even = 0;

        for (int j = 0; j < n; j++) {
            if (arr[j] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }

      
        if (n % 2 == 1) {
            
            cout << -1 << endl;
        } else {
            int ans = abs(odd - even) / 2;
            cout << ans << endl;
        }
    }

    return 0;
}
