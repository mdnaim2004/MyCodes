#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int sum = 0;
    for(int i=0; i<n ;i++){
        sum += v[i];
    }

    int left = 0;
    for(int i=0; i<n; i++){
        int right = sum-left-v[i];

        if(left == right){
            cout << i << endl;
            return 0;
        }
        left += v[i];
    }

    //cout << sum << endl;
    
    // for(int i=0; i<n; i++){
    //     cout << v[i] <<" ";
    // }
    return 0;
}




// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int totalSum = 0;
//     for(int x : arr) {
//         totalSum += x;
//     }

//     int leftSum = 0;
//     for(int i = 0; i < n; i++) {
//         int rightSum = totalSum - leftSum - arr[i];

//         if(leftSum == rightSum) {
//             cout << i << endl;
//             return 0;
//         }

//         leftSum += arr[i];
//     }

//     //cout << -1 << endl; // equilibrium index না থাকলে
//     return 0;
// }
