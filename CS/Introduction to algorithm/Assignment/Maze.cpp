#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
pair<int, int> parent[1005][1005];
int n, m;

vector<pair<int, int>> d = {{0,1}, {0, -1}, {-1,0}, {1, 0}};

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});

    vis[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty()){
        pair<int ,int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        //cout << par_i << " " << par_j << endl;

        for(int i=0; i<4; i++){
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if(valid(ci,cj) && !vis[ci][cj] &&grid[ci][cj] != '#'){
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}


int main(){

    //int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];

    int sr, sc, er, ec;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'R'){
                sr = i;
                sc = j;
            }
            if(grid[i][j] == 'D'){
                er = i;
                ec = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    bfs(sr, sc);

    //cout << vis[er][ec] << endl;

    if(vis[er][ec]  == 1){

        int r = er, c = ec;

        while(true){
            pair<int, int> p = parent[r][c];
            r = p.first;
            c= p.second;

            if(grid[r][c] == 'R'){
                break;
            }
            grid[r][c] = 'X';
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << grid[i][j];
            }
            cout << endl;
        }

    }
    else{
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << grid[i][j];
            }
            cout << endl;
        }
    }


    return 0;
}