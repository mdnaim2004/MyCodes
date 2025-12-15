
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

    int flag = 100;
    
    if(n==m){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == j) || (i + j == n - 1)) {
                    if(arr[i][j] != 1) {
                        printf("NO\n");
                        flag = 200;
                        return 0;
                    }
                }
                else{
                    if(arr[i][j] != 0) {
                        printf("NO\n");
                        flag = 200;
                        return 0;
                    }
                }
            }
        }
        if(flag == 100){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        
    }
    else{
        printf("NO\n");
        return 0;
    }

    return 0;
}