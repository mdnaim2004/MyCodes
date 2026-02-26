#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];

void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});

    vis[si][sj] = true;

    while(!q.empty()){
        pair<int ,int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        cout << par_i << " " << par_j << endl;

        for(int i=0; i<4; i++){
            int ci = par_i + d[i]
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];

    int si, sj;
    cin >> si >> sj;

    bfs()


    return 0;
}