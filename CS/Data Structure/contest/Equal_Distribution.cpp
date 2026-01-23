#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, k;

    cin >> n >> k;
   

    long long int x = k / n;
    long long int y = k % n;

    cout << x <<" "<< y <<endl;
}