#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0 ;i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int q;
    cin >> q;
    while(q--){
        int val;
        cin >> val;
        int flag = 200;
        // for(int i=0 ;i<n; i++){
        //     if(arr[i] == val){
        //         flag = 100;
        //     }
        // }

        int l=0;
        int r = n-1;
        while(l<=r){
            int mid = (l+r)/2;

            if(arr[mid] == val){
                flag = 100;
                break;
            }
            else if(arr[mid] < val){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(flag == 100){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
