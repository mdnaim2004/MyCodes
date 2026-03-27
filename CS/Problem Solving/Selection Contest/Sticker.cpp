#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];

    }
    map<long long int, long long int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]] += (i+1);
    }
    for(auto x : mp){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}