#include<bits/stdc++.h>
using namespace std;

int grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};

int n,m;
bool valid(int i, int j){
    if(i < 0 || i >= n || j< 0 || j>=m) 
        return false;
    return true;
}

bool range;

void dfs(int si, int sj){

    vis[si][sj] = true;

    if(si == 0 || si == n-1 || sj == 0 || sj == m-1){
        range = true;
    }

    for(int i=0; i<4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == 1)){
            dfs(ci, cj);
        }     

    }
}

int main(){
    //int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string s;
        cin >>s;
        for(int j=0; j<m; j++){
            grid[i][j] = s[j] - '0';
        }
        
    }
        

    memset(vis, false, sizeof(vis));

    int bodr = 0;
    int cent = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                range = false;
                dfs(i, j);
                
                if(range == true)
                    bodr++;
                else
                    cent++;
            }
        }
    }

    if(bodr > cent){
        cout << "Yes" << endl;
        cout << bodr << " " << cent << endl;
    }
    else{
        cout << "No" << endl;
    }


    return 0;
}