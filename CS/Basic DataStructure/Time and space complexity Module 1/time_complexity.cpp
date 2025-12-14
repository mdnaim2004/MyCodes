#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // using loop

    // int arr[n];
    // for(int i=1; i<=n; i++){
    //     cin>>arr[i];
    // }
    // int sum = 0;
    // for(int i=1; i<=n; i++){
    //     sum +=i;
    // }

    //using formula

    int sum = (n*(n+1))/2;

    cout << sum << endl;
    return 0;
}
