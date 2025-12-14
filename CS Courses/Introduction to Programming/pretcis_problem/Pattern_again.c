#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            printf("%d", j);
        }
        printf("\n");
        
    }
    for(int i = n-1; i>=1; i--){
        for(int j=n-i; j>0; j--){
            printf("%d", j);
        }
    }
}