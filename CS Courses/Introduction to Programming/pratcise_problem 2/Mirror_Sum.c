#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &b[i]);
    }


    for(int i=0; i<n; i++){
        int sum = a[i] + b[n-1-i];
        printf("%d ", sum);
    }

    return 0;
}
