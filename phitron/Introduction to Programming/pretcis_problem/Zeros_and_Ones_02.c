#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=1; i<=n; i++){
        scanf("%d ", &arr[i]);
    }
    int indx;
    scanf("%d", &indx);

    if(arr[indx] == 0){
        arr[indx] = 1;
    }
    else if(arr[indx] = 1){
        arr[indx] = 0;
    }

    for(int i=1; i<=n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}