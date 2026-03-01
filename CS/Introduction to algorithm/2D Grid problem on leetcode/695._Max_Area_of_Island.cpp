#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool vis[55][55];
    vector<pair<int,int>> d = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int m, n, count, mx;

    bool valid(int i, int j){
        return !(i < 0 || i >= n || j < 0 || j >= m);
    }

    void dfs(int si, int sj, vector<vector<int>>& grid){
        vis[si][sj] = true;
        count++;

        for(int i=0; i<4; i++){
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            if(valid(ci, cj) && grid[ci][cj] == 1 && !vis[ci][cj]){
                dfs(ci, cj, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        memset(vis, false, sizeof(vis));

        mx = 0; // ✅ initialize here

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count = 0;
                    dfs(i, j, grid);
                    mx = max(mx, count);
                }
            }
        }
        return mx; // ✅ return max
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << "\n";

    return 0;
}