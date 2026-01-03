#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int x;
    cin >> x;

    if ( x == 0){
        cout << 0 << endl;
        return 0;
    }
    else{
        long long int cource = (500 + x - 1) / x;
        cout << cource << endl;
    }
    return 0;
}
