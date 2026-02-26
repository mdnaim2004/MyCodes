#include<bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];

int level[105][105];

vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,-1}, {0,1}}; //movement......

int n,m;

bool valid(int i, int j){ // checking this value is valid or non valid......
    if(i<0 || i >= n || j<0 || j >= m) return false;
    else return true;
}

void bfs(int si,int sj){
    queue<pair<int,int>> q;
    q.push({si, sj});
    vis[si][sj] = 0;

    level[si][sj] = true;

    while(!q.empty()){
        pair<int,int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

        //cout << par_i << " " << par_j << endl;

        for(int i=0; i<4; i++){
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.'){ // check this value is valid and non visited....
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
        
    }


}


int main(){
    // int n,m;
    cin >>n >>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level)); // initial value is -1
    bfs(si, sj);
    cout << level[di][dj] << endl; // print shortest path....
    return 0;
}