#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int i=0;
    int j=n-1;
    int pair = 0;
    while(i<j){
        if(arr[i] % 2 == 0 && arr[j] % 2 == 1){
            pair++;
            //printf("%d", pair);
        }
        i++;
        j--;
        //printf("%d", pair);
    }

    printf("%d", pair);

    return 0;
}


