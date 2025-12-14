#include<stdio.h>
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int i = n-1;
    for(int j=0; j<m; j++){
        printf("%d ", arr[i][j]);
    }
    printf("\n");

    int j = m-1;
    for(int i=0; i<n; i++){
        printf("%d ", arr[i][j]);
    }

    return 0;
}