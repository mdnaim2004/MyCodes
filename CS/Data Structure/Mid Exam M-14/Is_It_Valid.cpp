#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        stack<char> st;

        for(char ch : s){
            if (!st.empty() && st.top() != ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        if(st.empty()){
            cout <<"YES"<<endl;
        }
        else{
            cout << "NO" <<endl;
        }
    }
}