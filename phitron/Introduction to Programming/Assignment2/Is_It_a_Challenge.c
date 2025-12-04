#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    if(n > 0){
        for(int i=1; i<=n; i++){
            printf("%d ",i);
        }
    }
    else {
        for(int j=n; j<=0; j++){
            printf("%d ",j);
        }
    }
    return 0;
}