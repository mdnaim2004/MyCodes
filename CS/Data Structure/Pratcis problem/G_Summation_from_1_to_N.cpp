#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> arr(n);

    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
    }
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum +=arr[i];
    }
    cout << sum << endl;

    return 0;
}
