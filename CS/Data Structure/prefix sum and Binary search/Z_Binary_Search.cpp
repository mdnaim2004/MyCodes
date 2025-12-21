#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector <int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<int> quire(q);
    for(int i=0; i<q; i++){
        cin >> quire[i];
    }
    for(int i=0; i<q; i++){
        if(v[i] == quire[i]){
            cout<<"found"<<endl;
        }else{
            cout << "not found" << endl;
        }
    }
    return 0;
}
