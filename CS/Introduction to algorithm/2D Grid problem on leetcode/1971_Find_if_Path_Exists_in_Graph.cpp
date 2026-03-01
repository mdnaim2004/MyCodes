#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int> adj_list[2000005];
bool vis[2000005];

void dfs(int src){
    vis[src] = true;
    for(int child : adj_list[src]){
        if(!vis[child])
            dfs(child);
    }
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0; i<edges.size(); i++){

            int a = edges[i][0]; // i = 0; or... 0 number index e ase ami 1st value nilam, then....
            int b = edges[i][1]; // akheneo same, 1 no index e ase 2nd value nilam

            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
        memset(vis, false, sizeof(vis));

        dfs(source);

        if(vis[destination] == true) // return(vis[destination] == true);
            return true;
        return false;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;   // number of nodes, number of edges

    vector<vector<int>> edges(m, vector<int>(2));
    for(int i = 0; i < m; i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    int source, destination;
    cin >> source >> destination;

    Solution sol;
    bool ans = sol.validPath(n, edges, source, destination);

    if(ans) cout << "true\n";
    else cout << "false\n";

    return 0;
}