// // brut force solution

// // #include<bits/stdc++.h>
// // using namespace std;
// // int main(){

// //     int n, q;
// //     cin >> n >> q;

// //     vector<int> v(n+1);

// //     for(int i=1; i<=n; i++){
// //         cin >> v[i];
// //     }

// //     while(q--){
// //         int l, r;
// //         cin >> l >> r;

// //         int sum = 0;
// //         for(int i=l; i<=r; i++){
// //             sum += v[i];
// //         }

// //         cout << sum << endl;
// //     }

// //     return 0;
// // }


// // standard solution




// // brut force solution

// #include<bits/stdc++.h>
// using namespace std;
// int main(){

//     int n, q;
//     cin >> n >> q;

//     vector<long long int> v(n+1);

//     for(int i=1; i<=n; i++){
//         cin >> v[i];
//     }

//     vector<long long int> pre(n+1);
//     pre[1] = v[1];
//     for(int i=2; i<=n; i++){
//         pre[i] = pre[i-1]+v[i];
//     }

//     //output of prefixsum........
//     // for(int i=1; i<=n; i++){
//     //     cout << pre[i] << " ";
//     // }

//     while(q--){
//         int l, r;
//         cin >> l >> r;

//         // int sum = 0;
//         // for(int i=l; i<=r; i++){
//         //     sum += v[i];
//         // }
//         long long int sum;
//         if(l == 1){
//             sum = pre[r];
//         }
//         else{
//             sum = pre[r] - pre[l-1];
//         }

//         cout << sum << endl;
//     }

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin>> n >> q;

    vector<long long int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    vector<long long int> prefix_sum_of(n);
    prefix_sum_of[0] = v[0];
    for(int i=1; i<n; i++){
        prefix_sum_of[i] = prefix_sum_of[i-1] + v[i];
    }

    // //output of prefix sum
    // for(int i=0; i<n; i++){
    //     cout << prefix_sum_of[i]<< " ";
    // }

    long long int sum;
    while(q--){
        int l,r;
        cin >> l >>r;

        if(l==0){
            sum = prefix_sum_of[r];
        }
        else{
            sum = prefix_sum_of[r] - prefix_sum_of[l-1];
        }
        cout << sum << endl;
    }

    return 0;
}
