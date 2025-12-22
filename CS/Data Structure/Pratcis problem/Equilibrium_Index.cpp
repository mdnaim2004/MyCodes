#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int sum = 0;
    for(int i=0; i<n ;i++){
        sum += v[i];
    }

    cout << sum << endl;
    
    for(int i=0; i<n; i++){
        cout << v[i] <<" ";
    }
    return 0;
}
