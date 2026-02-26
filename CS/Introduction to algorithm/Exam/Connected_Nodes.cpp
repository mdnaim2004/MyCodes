#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n];

    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);

    }

    int q;
    cin >>q;
    while(q--){
        int x;
        cin  >> x;

        if(adj_list[x].empty()){
            cout << -1 <<endl;
            continue;
        }

        sort(adj_list[x].begin(), adj_list[x].end(), greater<int>());

        for(int x : adj_list[x]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}