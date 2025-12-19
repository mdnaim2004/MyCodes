#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8};
    //cout << v[7] << endl;
    
    //cout<<v.front() << endl;

    //cout<<v.back() << endl;

    //cout <<v[v.size() - 1]<<endl;

    for(auto it = v.begin(); it<v.end(); it++){
        cout << *it<<" ";
    }
    return 0;
}
