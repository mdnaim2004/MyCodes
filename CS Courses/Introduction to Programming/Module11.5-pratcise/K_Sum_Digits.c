#include<stdio.h>
int main(){

    int n;
    scanf("%d", &n);

    char arr[n];

    for(int i=0; i<n; i++){
        scanf("%s", &arr[i]);
    }

    int sum = 0;

    for(int i=0; i<n; i++){
        sum += arr[i] - '0';
    }
    printf("%d", sum);

    return 0;
}