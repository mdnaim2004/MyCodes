#include<bits/stdc++.h>
using namespace std;
int main(){
    //int a[5];   // static array --> static array onno function theke return korle value paua jai na.



    int *a = new int[5];  // dynamic array. --> onno function theke return korle ami value pabo ....orthat onno function theke return korle ai value delit hoy na ,,,,,,but static memory te jodi initiliz kori tahole aita onno function theke value pabo na.

    for(int i=0;i<5; i++){
        cin >> a[i];
    }
    for(int i=0; i<5; i++){
        cout << a[i] << " " ;
    }
    return 0;
}