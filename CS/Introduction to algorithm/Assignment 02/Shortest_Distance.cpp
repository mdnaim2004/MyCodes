#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;

    long long int adj_mat[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = LLONG_MAX;
            
        }
    }

    while(e--){
        int a, b, c;
        cin >> a >> b >> c;

        adj_mat[a][b] = c;
    }
    return 0;
}