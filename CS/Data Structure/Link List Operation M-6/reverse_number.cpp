#include <bits/stdc++.h>
using namespace std;
void recurtion(int i, int n){
    if(i > n){
        return;
    }
    cout << i << endl;
    recurtion(i+1, n);
    cout << i << endl;
}
int main() {
    int n=5;
    recurtion(1, n);
    return 0;
}
