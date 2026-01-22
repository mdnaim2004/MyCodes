#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int m;

    cin >> n;
    cin >> m;

    int *st = new int[n];
    int *q = new int[m];

    if(m != n){
        cout << "NO" <<endl;
        return 0;
    }
    else{
        for(int i=0; i<n; i++){
            cin >> st[i];
        }
        for(int i=0; i<m; i++){
            cin >> q[i];
        }

        int i=0;
        while(i<n && i<m){
            if(st[n-1-i] != q[i]){
                cout << "NO" << endl;
                return 0;
            }
            i++;
        }
    }
    cout << "YES\n";
}