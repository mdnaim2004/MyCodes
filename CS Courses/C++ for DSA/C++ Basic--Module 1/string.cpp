#include<iostream>
using namespace std;

int main(){
    // char s[100];
    // cin >> s;
    // cout << s << endl;


    // c program e use kora hoto fgets(s, 100);  ja space soho neaua hoto...... to c++ a amon akta function ase space soho naua jai seta holo cin.getline(s, 100);

    //successfully its runinig....
    // cin.getline(s, 100);
    // cout << s << endl;


    // but jodi ami 1st e akta integer value nei tahole aita kaj korbe na...

    // but ami jodi cin.ignore(); use kori tahole sothik vabe run korbe...

    int x;
    cin >> x;
    cin.ignore();
    char s[100];
    cin.getline(s, 100);
    cout << x << endl << s << endl; 


    return 0;
}