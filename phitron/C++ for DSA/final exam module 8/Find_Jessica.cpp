#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    stringstream ss(s);
    string word;

    int flag =100;

    while(ss>>word){
        if(word == "Jessica"){
            flag = 200;
            break;
        }
    }
    if(flag == 200){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" <<endl;
    }
    return 0;
}
