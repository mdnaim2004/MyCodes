#include<stdio.h>
int main(){
    //printf("Hello World");
    int n;
    scanf("%d", &n);

    int arr[n+1];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    // for(int i=0; i<=n; i++){
    //     printf("%d\t", arr[i]);
    // }

    int indx, value;
    scanf("%d %d", &indx, &value);

    for(int i=n; i>=indx+1; i--){
        arr[i] = arr[i-1];
        
    }
    arr[indx] = value;

    for(int i=0; i<=n; i++){
        //arr[indx] = value;
        printf("%d\t", arr[i]);
        
    }

    return 0;
}