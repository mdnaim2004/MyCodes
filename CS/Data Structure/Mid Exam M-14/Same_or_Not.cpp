#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    queue <int> q;
    int n,m;
    cin >> n >> m;

    int val;

    if(n!=m){
        cout << "NO";
    }
    else{
        for(int i=0; i<n; i++){
            cin >> val;
            st.push(val);
        }
        for(int i=0; i<m; i++){
            cin >> val;
            q.push(val);
        }

        while(!st.empty() && !q.empty()){
            if(st.top() != q.front()){
                cout << "NO" <<endl;
                return 0;

            }
            st.pop();
            q.pop();
        }
        cout << "YES" << endl;
    }
    return 0;
}