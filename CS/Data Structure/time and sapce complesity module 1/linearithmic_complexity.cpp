#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){//complexity O(n)
        for(int j=1; j<n; j*=2){ //complexity O(log n)
            cout << "hello"<<endl;
        }
    }

    //overall complexity O(n log n)
    return 0;
}
