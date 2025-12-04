#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int salami = 0;
    for(int i=0; i<n; i++){
        salami = max - arr[i];
        printf("%d ", salami);
    }
}