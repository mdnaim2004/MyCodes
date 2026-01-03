#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int frek[26] = {0};
    for(int i=0; i<s.size(); i++){
        // cout << s[i] << endl;
        
        char ch = s[i];
        frek[ch - 'a']++;

    }
    for(int i=0; i<s.size(); i++){
        if(frek[s[i] - 'a'] == 1){
            cout << s[i] << endl;
            return 0;
        }
    }
    cout <<-1 << endl;
    return 0;
}
