#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;

    int adj_mat[n][n];
    
    while(e--){
        int a, b, c;
        cin >> a >> b >> c;

        adj_mat[a][b] = c;
        //adj_mat[b][a] = c; //if undirected.....
    }
    return 0;
}