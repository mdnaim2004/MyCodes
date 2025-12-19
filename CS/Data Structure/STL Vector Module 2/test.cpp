#include <bits/stdc++.h>
using namespace std;

int main() {
    // int a[4] = {12,13,14,15};
    // vector<int> v(a, a+4);
    // cout<<  v[3] <<endl;

    //vector<int> v={1,2,3,4};
    // v.resize(2);
    // v.resize(4);
    // v.pop_back();

    vector<int> v={1,2,3,4,5};
    v.erase(v.begin()+2, v.end());
    for(int x : v){
        cout<<x << " ";
    }
    return 0;
}
