#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int level[105][105];

vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

int n,m; 

void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});

    vis[si][sj] = true;
    level[si][sj] = 0;

    bool valid(int i, int j){
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }

    while(!q.empty()){
        pair<int ,int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        cout << par_i << " " << par_j << endl;

        for(int i=0; i<4; i++){
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == 'P'){
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}



int main(){
    // int n,m;
    cin >> n ;
    int si, sj, di, dj;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S'){
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'E'){
                di = i;
                dj = j;
            }
        }
           
    }

    cout << si << " "  << sj << endl << di << " "<< dj << endl;


    // memset(vis,false,sizeof(vis));
    // bfs(si, sj);


    return 0;
}