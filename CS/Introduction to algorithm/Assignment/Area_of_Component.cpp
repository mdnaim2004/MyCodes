#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];


int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> grid[i][j];

    return 0;
}