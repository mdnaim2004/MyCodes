#include<stdio.h>

void rev_arr(int arr[], int n, int i){
    if(i == n){
        return;
    }
    rev_arr(arr, n, i+1);
    printf("%d ", arr[i]);
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    rev_arr(arr, n, 0);

    return 0;
}