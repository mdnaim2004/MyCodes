#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count;
    bool vis[105][105];
    vector<pair<int, int>> d = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int m,n;

    bool valid(int i, int j){
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }

    void dfs(int si, int sj, vector<vector<int>>& grid){
        vis[si][sj] = true;
        for(int i=0; i<4; i++){
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            if(!valid(ci, cj)) {
                count++;          // boundary
            }
            else if(grid[ci][cj] == 0) {
                count++;          // water
            }
            else if(!vis[ci][cj] && grid[ci][cj] == 1) {
                dfs(ci, cj, grid);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        count = 0;
        n = grid.size();
        m = grid[0].size();

        memset(vis, false, sizeof(vis));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    cout << "Perimeter = " << sol.islandPerimeter(grid) << endl;

    return 0;
}