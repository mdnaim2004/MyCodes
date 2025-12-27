#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // for(int i=0; i<n; i++){
    //     // cout << arr[i] << " ";
    //     if(arr[i] == )
    // }
    int i=0;
    int j = i+1;

    int flag = 100;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                flag = 2000;
                break;
            }
        }
    }
    if (flag == 100){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" <<endl;
    }
    return 0;
}
