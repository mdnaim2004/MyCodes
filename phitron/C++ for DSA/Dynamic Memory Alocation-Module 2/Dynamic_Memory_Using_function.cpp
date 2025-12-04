#include<bits/stdc++.h>
using namespace std;

int *p;
void fun(){
    int *x = new int;
    *x = 20;
    p = x;
    cout << *p << endl;
    return;
}
int main(){
    fun();
    cout << *p << endl;
    return 0;
}