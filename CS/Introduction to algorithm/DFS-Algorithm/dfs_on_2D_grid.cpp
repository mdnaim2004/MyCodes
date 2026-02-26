#include<bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];

int n,m;

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int si,int sj){
    cout << si << " " << sj << endl;
    vis[si][sj] = true;

    for(int i=0; i<4; i++){
        int ci,cj;
        ci = si + d[i].first;
        cj = sj + d[i].second;

        //cout << ci << " "  << cj << endl;

        if(valid(ci,cj) && !vis[ci][cj])
            dfs(ci,cj);
    }
}


int main(){
    
    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];

    int si,sj;
    cin >> si >> sj;

    memset(vis,false,sizeof(vis));
    dfs(si,sj);
    
    return 0;
}