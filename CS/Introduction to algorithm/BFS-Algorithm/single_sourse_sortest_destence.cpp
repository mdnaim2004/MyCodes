#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int level[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;

            }
        }
    }
}


int main(){
    int n, e;
    cin >> n >> e;

    while(e--){
        int a, b;
        cin >> a >> b ;
        adj_list [a].push_back(b);
        adj_list [b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));

    int src, dest;
    cin >> src >> dest;

    bfs(src);

    for(int i=0; i<n; i++){
        cout << i <<" => " <<level[i] <<endl;
    }

    //cout << level[dest] << endl;

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// char grid[1005][1005];
// bool vis[1005][1005];
// int level[1005][1005];

// vector<pair<int,int>> d = {{0,1},{0,-1},{-1,0},{1,0}};
// int n, m;

// bool valid(int i, int j){
//     return (i >= 0 && i < n && j >= 0 && j < m);
// }

// void bfs(int si, int sj){
//     queue<pair<int,int>> q;
//     q.push({si, sj});
//     vis[si][sj] = true;
//     level[si][sj] = 0;

//     while(!q.empty()){
//         auto [pi, pj] = q.front();
//         q.pop();

//         for(auto [dx, dy] : d){
//             int ci = pi + dx;
//             int cj = pj + dy;

//             if(!valid(ci, cj)) continue;
//             if(vis[ci][cj]) continue;
//             if(grid[ci][cj] == '#') continue; // wall

//             vis[ci][cj] = true;
//             level[ci][cj] = level[pi][pj] + 1;
//             q.push({ci, cj});
//         }
//     }
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> m;

//     pair<int,int> src = {-1, -1}, dest = {-1, -1};

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             cin >> grid[i][j];
//             if(grid[i][j] == 'A') src = {i, j};
//             if(grid[i][j] == 'B') dest = {i, j};
//         }
//     }

//     // তোমার মতো করে reset
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             vis[i][j] = false;
//             level[i][j] = -1;
//         }
//     }

//     bfs(src.first, src.second);

//     if(vis[dest.first][dest.second]) cout << "YES\n";
//     else cout << "NO\n";

//     // চাইলে distance print করতে পারো:
//     // cout << level[dest.first][dest.second] << "\n";

//     return 0;
// }