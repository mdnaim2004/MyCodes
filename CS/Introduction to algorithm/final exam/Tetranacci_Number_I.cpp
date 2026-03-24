#include<bits/stdc++.h>
using namespace std;

int dp[1005];

int treta(int n){
    
    if(n == 0)
        return n;
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;
    if(n == 3)
        return 2;

    if(dp[n] != -1)
        return dp[n];
   
    return dp[n] = treta(n-1) + treta(n-2) + treta(n-3)+ treta(n-4);
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << treta(n);
    return 0;
}