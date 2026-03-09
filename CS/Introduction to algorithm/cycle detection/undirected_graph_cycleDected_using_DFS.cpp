#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool vis[1000];
int parent[1000];
bool cycle;

void dfs(int src){
    vis[src] = true;

    for(int child : adj_list[src]){
        if(vis[child] == false){
            dfs(child);
            parent[child] = src;
        }
    }
}

int main(){
    int n,e;
    cin >> n >> e;

    while(e--){
        int a, b;
        cin >>a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(false));
    memset(parent,-1, sizeof(parent));

    cycle = false;

    for(int i=0; i<n; i++){
        if(vis[i] == false){
            dfs(i);
        }
    }
    for(int i=0; i<n; i++){
        cout << i << " parent " << parent[i] << endl;
    }
    return 0;
}