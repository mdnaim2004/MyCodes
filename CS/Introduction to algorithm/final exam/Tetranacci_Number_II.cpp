#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long int treta[n+1];
    treta[0] = 0;
    treta[1] = 1;
    treta[2] = 1;
    treta[3] = 2;

    for(int i=4; i<=n; i++)
        treta[i] = treta[i-1]+ treta[i-2] +treta[i-3] + treta[i-4];
    
    cout << treta[n] << endl;
    return 0;
}