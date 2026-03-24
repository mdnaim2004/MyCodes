#include<bits/stdc++.h>
using namespace std;

int dp[100005];

bool rec(int cur, int tar){
    if(cur == tar)
        return true;
    if(cur > tar) 
        return false;

    if(dp[cur] != -1)
        return dp[cur];

    bool opt1 = rec(cur+3, tar);
    bool opt2 = rec(cur*2, tar);

    return dp[cur] = (opt1 || opt2);

}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;

        if(rec(1,n) == true)
            cout<<"YES"<< endl;
        else
            cout<<"NO" << endl;
    }
    return 0;
}