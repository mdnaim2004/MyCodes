#include<bits/stdc++.h>
using namespace std;

bool pile(string s1, string s2){

    if(s1.size() != s2.size())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return (s1 == s2);
}

int main(){
    int n;
    cin >> n;

    while(n--){
        string s1, s2;
        cin >> s1 >> s2;

        if(pile(s1, s2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}