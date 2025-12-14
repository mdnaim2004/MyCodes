#include<stdio.h>

void array_print(int arr[], int n, int i){

    if(i == n){  //base case
        return;
    }
    //array_print(arr,n, i+1);// aikhene dile reverse array print korbe......50 40 30 20 10
    printf("%d \n", arr[i]);
    array_print(arr,n, i);//aikhene dile normal arrar print korbe.......10 20 30 40 50
    
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    array_print(arr, n, 0);

    return 0;
}