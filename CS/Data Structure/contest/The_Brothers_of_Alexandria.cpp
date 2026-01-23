#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;

    cin >> n >> k;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    // for(int i=0; i<n; i++){
    //     cout << arr[i] << " ";

    //     // if(arr[i] == k){
    //     //     cout << arr[i] << endl;
    //     //     break;
    //     // }
    // }
    cout << arr[k-1] << endl;

}