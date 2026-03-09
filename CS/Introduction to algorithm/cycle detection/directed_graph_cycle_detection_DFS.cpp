#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[100005];
bool vis[100005];
int parent[100005];
bool cycle;

void dfs(int src){
    vis[src] = true;

    for(int child : adj_list[src]){
        
        if(vis[child] && parent[src] != child){
            cycle = true;
        }
        if(vis[child] == false){
            parent[child] = src;  //this are actually processs....
            dfs(child);
            
        }
    }
}

int main(){
    int n,e;
    cin >> n >> e;

    while(e--){
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    cycle = false;

    for(int i=0; i<n; i++){
        if(vis[i] == false){
            dfs(i);
        }
    }

    for(int i=0; i<n; i++){
        cout << i << " parent " << parent[i] << endl;
    }

    if(cycle) cout << "Cycle detected"<< endl;
    else cout << "No Cycle" << endl;

    return 0;
}