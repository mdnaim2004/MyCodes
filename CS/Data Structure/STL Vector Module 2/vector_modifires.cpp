#include <bits/stdc++.h>
using namespace std;

int main() {

    //vecto copy
    // vector<int> v = {1,2,3,4,5};
    // vector<int> v2 ;
    // v2 = v;
    // for(int i=0; i<v2.size(); i++){
    //     cout << v2[i] << " ";
    // }

    
    // vector<int> v = {1,2,3,4,5};
    // v.pop_back();
    // v.pop_back();


    //vector insert

    // vector<int> v = {1,2,3,4,5};
    // v.insert(v.begin()+3, 500);

    //insert multiple

    vector<int> v = {1,2,3,4,5};
    // vector<int>v2 = {100, 200, 300,};
    // v.insert(v.begin()+3,v2.begin(), v2.end());

    v.erase(v.begin()+2,v.begin()+5);

    for(int x : v){
        cout<< x << " ";
    }
    return 0;
}
