#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};

int n,m;
bool valid(int i, int j){
    if(i < 0 || i >= n || j< 0 || j>=m) 
        return false;
    return true;
}

bool dfs(int si, int sj){

    if(grid[si][sj] == 'D')
        return true;

    vis[si][sj] = true;

    for(int i=0; i<4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D')){
            if(dfs(ci, cj)){
                if(grid[si][sj] != 'R' && grid[si][sj] != 'D')
                    grid[si][sj] = 'X';
                return true;
            }
        }     

    }
    return false;
}

int main(){
    //int n,m;
    cin >> n >> m;

    int si, sj;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[i][j] == 'R'){
                si = i;
                sj = j;
            }
             
    memset(vis, false, sizeof(vis));
    dfs(si, sj);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }


    return 0;
}