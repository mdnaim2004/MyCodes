#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int xth, value;
    scanf("%d %d", &xth, &value);
    for(int i=n-1; i>=0; i--){
        //printf("%d ", arr[i]);
        if(i == xth){
            arr[xth] = value;
        }
        printf("%d ", arr[i]);
    }
    
    return 0;
}