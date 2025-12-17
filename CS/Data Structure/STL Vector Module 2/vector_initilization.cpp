#include <bits/stdc++.h>
using namespace std;

int main() {

    //type 1
    //vector <int> v;
    //cout << v.size();

    //type 2
    // vector<int> v(5);
    // cout << v.size() << endl;

    //type 3
    // vector <int> v(5, 0);
    // for(int i=0; i<v.size(); i++){
    //     cout << v[i] << " " <<endl;
    // }

    //type 4
    //vector<int> v(10, -1);
    //vector<int> v2(v);
    //for(int i=0;i<v.size();i++){
    //    cout << v[i] <<" ";
    //}

    //type 5

    // int arr[5] = {1,2,3,4,5};
    // vector<int> v(arr, arr+5);
    // for(int i=0; i<v.size(); i++){
    //     cout << v[i] << " ";
    // }

    //type 6
    vector<int> v = {1,2,3,4,5};
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
