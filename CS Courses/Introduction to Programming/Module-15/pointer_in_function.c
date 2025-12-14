#include<stdio.h>
int main(){
    int arr[5] = {10, 20, 30, 40, 50};

    // printf("%p\n", &arr[0]);
    // printf("%p\n", &arr[1]);
    // printf("%p\n", &arr[2]);
    // printf("%p\n", &arr[3]);




    printf("address of  array in 0 index = %p\n", &arr[0]);
    printf("address of  array in 0 index = %p\n", &arr);

    

    printf("%d\n", *arr);

    *(arr+3) = 100;
    printf(" change in value of 0 index = %d\n", arr);
    for(int i=0; i<5; i++){
        printf(" %d ", arr[i]);

    }
    return 0;
}