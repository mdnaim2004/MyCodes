#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;
    vector<int>arr(n);

    vector<int> odd;
    vector<int> even;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        if(arr[i] % 2 == 0){
            even.push_back(arr[i]);
        }
        else{
            odd.push_back(arr[i]);
        }
    }

    for(int ev : even ){
        cout << ev << " ";
    }
    for( int od : odd){
        cout << od << " ";
    }
}