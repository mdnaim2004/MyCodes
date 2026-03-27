#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;

    cin >> s;

    map<char, int> fre;

    for(char c : s){
        fre[c] ++;
    }

    vector<pair<int, char>> odd,even;

    for(auto x : fre){
        char c = x.first;
        int f = x.second;
        if(f % 2 == 0){
            even.push_back({f, c});
        }
        else{
            odd.push_back({f, c});
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    
    string ans = "";

    for(auto x : odd){
        ans += string(x.first, x.second);
    }
    for(auto x : even){
        ans += string(x.first, x.second);
    }

    cout << ans << endl;

    return 0;
}