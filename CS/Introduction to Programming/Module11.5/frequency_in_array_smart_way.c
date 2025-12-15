#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
   

    int fre[6] = {0};

    for(int i=0; i<n; i++){
        int val = arr[i];
        fre[val]++;

    }
    for(int i=0; i<6; i++){
        printf("%d --> %d\n", i, fre[i]);
    }
    return 0;
}