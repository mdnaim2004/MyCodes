#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, q;
    cin >> n>> m>> q;
    int adj_mat[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INT_MAX;
        }
    }

    while(m--){
        int a, b, c;
        cin >> a>>b >> c;

        adj_mat[a][b] = c;
        adj_mat[b][a] = c;
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){ 
                //cout << i << " " << k << " " << j << endl;

                if(adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && adj_mat[i][k] + adj_mat[j][k] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }  
    }
    while(q--){
        int s, d;
        cin >> s >> d;
        if(adj_mat[s][d] == INT_MAX) cout << -1 << endl;
        else cout << adj_mat[s][d] << endl;
    }

    return 0;
}