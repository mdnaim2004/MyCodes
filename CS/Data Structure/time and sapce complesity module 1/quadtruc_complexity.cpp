#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m, l;
    cin>>n >>m >>l;

    //time complwxity of order of O(n*n)
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << "hello" << endl;
    //     }
    // }
    

    // time complexity of order of O(n*m)

    // for(int i=0; i<n;i++){
    //     for(int j=0; j<m; j++){
    //         cout << "hello" << endl;
    //     }
    // }


    //time complexity of order of O(l*n*m)

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<l; k++){
                cout << "Hello" << endl;
            }
        }
    }
    return 0;
}
