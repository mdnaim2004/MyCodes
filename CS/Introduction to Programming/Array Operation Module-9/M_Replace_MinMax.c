#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int min = INT_MAX;
    int max = INT_MIN;

    



    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // int temp = arr[min];
    // arr[min] = arr[max];
    // arr[max] = temp;

    // for(int i=0; i<n; i++){
    //     printf("%d ", arr[i]);
    // }


    // for(int i=0; i<n; i++){
    //     printf("%d ", arr[i]);
    // }

    return 0;
}