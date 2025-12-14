#include<iostream>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    // mininum number
    // if(a<b){
    //     cout << a << endl ;

    // }
    // else{
    //     cout<< b << endl ;
    // }
    
    // maximum number
    // if(a > b){
    //     cout << a <<endl;

    // }else{
    //     cout << b <<endl;
    // }

    //maximum number
    cout << max(a,b) << endl;

    //minimum number
    cout << min(a,b) << endl;

    // swaping number

    // int temp = a;
    // a = b;
    // b = temp;

    // cout <<"a = "<< a << ", " <<"b = "<< b << endl;

    swap(a,b);
    cout <<"a = "<< a << ", " <<"b = "<< b << endl;


    return 0;
}