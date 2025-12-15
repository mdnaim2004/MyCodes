#include<stdio.h>

void odd_even(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int odd = 0;
    int even = 0;

    for(int i=0; i<n; i++){
        if(arr[i] %2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }

    printf("%d %d\n", even, odd);

}

int main(){
    
    odd_even();
    return 0;
}