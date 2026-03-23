#include<bits/stdc++.h>
using namespace std;
int fibo(int n){
    // if(n==0){
    //     return 0;
    // }
    // if(n == 1){
    //     return 1;
    // }

    // if(n==0 || n == 1){
    //     return n;
    // }
    if(n < 2){
        return n;
    }
    return fibo(n-1) + fibo(n-2);
}
int main(){
    cout << fibo(9);
    return 0;
}