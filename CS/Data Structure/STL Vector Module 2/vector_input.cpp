#include <bits/stdc++.h>
using namespace std;

int main() {


    int n;
    cin >> n;


    //int arr[n];
    //vector<int> v(n);

    vector <int> v;


    for(int i=0; i<n; i++){
        //cin >> arr[i];
        //cin >> v[i];

        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0; i<n; i++){
        //cout<< arr[i]<< " ";
        cout << v[i] << " ";
    }
    return 0;
}
