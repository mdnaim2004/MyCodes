#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, q;
    cin >> n>> m>> q;
    long long int adj_mat[n+5][n+5];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = LLONG_MAX;
        }
    }

    while(m--){
        long long int a, b, c;
        cin >> a>>b >> c;

        adj_mat[a][b] = min(adj_mat[a][b], c);
        adj_mat[b][a] = min(adj_mat[b][a],c);
           
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){ 
                //cout << i << " " << k << " " << j << endl;

                if(adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && adj_mat[i][k] + adj_mat[j][k] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }  
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        if(adj_mat[x][y] == LLONG_MAX) 
            cout << "-1" << endl;
        else 
            cout << adj_mat[x][y] << endl;
    }

    return 0;
}