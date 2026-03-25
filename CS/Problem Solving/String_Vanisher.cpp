#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int ans = 0;
        int cur = n;

        while(cur > 0){
            ans++;
            cur = cur/2;

        }
        cout << ans << endl;
    }

    return 0;
}