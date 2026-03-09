#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1000];
bool vis[1000];

int parent[1000];

bool cycle;

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        //cout << par << endl;

        for(int child : adj_list[par]){
            if(vis[child] && parent[par] != child){
                cycle = true;
            }
            if(vis[child] == false){
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
        }
    }
}

int main(){
    int n, e;
    cin>> n >> e;
    
    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);

    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;

    for(int i=0; i<n; i++){
        if(vis[i] == false){
            bfs(i);
        }
    }
    if(cycle) cout << "cycle detected";
    else cout << "No cycle";
    
    return 0;
}