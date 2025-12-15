#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    //time complexity order of n.
    // for(int i=1; i<=n; i++){
    //     cout << i << " ";
    // }


    //divisor...........

    // operation come galo but ai code ke aro simplification kora jai....jar fole ai code aro optimise hoy
    // for(int i=1; i<=n; i++){
    //     if(n%i == 0){
    //         cout << i << " ";
    //     }
    // }

    //time complexity order of n.
    // for(int i=0; i<=n; i++){
    //     cout << i << " ";
    // }


    //time complexity order of O(sqrt n)
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            cout << i << " " << n/i << " ";
        }
    }
    return 0;
}
