#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int indx;
    scanf("%d", &indx);

    for(int i=indx; i<n-1; i++){
        arr[i] = arr[i + 1];
    }
    // printf("%d\n", arr[2]);
    n--;
    for(int i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}