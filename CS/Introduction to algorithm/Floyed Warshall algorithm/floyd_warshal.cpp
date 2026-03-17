#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;

    int adj_mat[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INT_MAX;
        }
    }
    
    while(e--){
        int a, b, c;
        cin >> a >> b >> c;

        adj_mat[a][b] = c;
        //adj_mat[b][a] = c; //if undirected.....
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //cout << i << " " << j << endl;
        }
    }
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         if(adj_mat[i][j] == INT_MAX)
    //             cout << "INF " ;
    //         else
    //             cout << adj_mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}