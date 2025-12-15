#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    //time complexity = O(n)
    // for(int i=0; i<n; i++){
    //     cout << i << " ";
    // }


    // time complexity = O(log n)......aitar log er base 2
    // for(int i = 1; i < n; i *= 2){
    //     cout << i << " ";
    // }


    //time complixity  = O(log n) .........aitar log er base 3
    for(int i = n; i > 0; i /= 2){
        cout << i << " ";
    }


    return 0;
}
