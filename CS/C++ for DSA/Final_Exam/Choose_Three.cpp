#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;

        int arr[size];

        int target;
        cin >> target;

        for (int j = 0; j < size; j++) {
            cin >> arr[j];
        }
        // cout << n << endl;
        // cout << size << " " << target << endl;
        // for(int j=0; j<size; j++){
        //     cout << arr[j] << " ";
        // }
        int flag = 0;
        for(int j=0; j<size; j++){
            for(int k=j+1; k<size; k++){
                for(int l = k+1; l<size; l++){
                    int sum = arr[j] + arr[k] + arr[l];
                    if(sum == target){
                        flag = 1;
                    }
                }
            }
        }
        if(flag==0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}
