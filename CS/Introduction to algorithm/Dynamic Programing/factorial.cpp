#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n == 1){
        return 1;
    }
    int mul = fact(n-1);
    return mul * n;
}

int main(){
    cout << fact(5);
    return 0;
}