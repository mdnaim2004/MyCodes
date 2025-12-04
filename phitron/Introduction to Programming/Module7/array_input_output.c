#include<stdio.h>
int main(){
    int arr[5];
    // scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    // printf("%d %d %d ", arr[1], arr[1], arr[2]);

    for (int  i = 0; i < 5; i++){
        scanf("%d ", &arr[i]);
    }
    for(int i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
    
    
    return 0;
}