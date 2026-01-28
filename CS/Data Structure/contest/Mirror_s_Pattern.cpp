#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // first line
    for(int i = 1; i <= n; i++) {
        cout << i;
    }
    cout << endl;

    // middle lines
    for(int i = 2; i <= n - 1; i++) {
        cout << i;
        cout << "   ";              // fixed 3 spaces
        cout << (n - i + 1) << endl;
    }

    // last line
    for(int i = n; i >= 1; i--) {
        cout << i;
    }
    cout << endl;

    return 0;
}
