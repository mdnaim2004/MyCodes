#include<bits/stdc++.h>
using namespace std;
#define ll long long

void rec(ll n){
    if(n == 0)
        return;
    
    rec(n/10);
    cout << n%10 << " ";
}

int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        rec(n);
        cout << endl;
    }
    return 0;
}