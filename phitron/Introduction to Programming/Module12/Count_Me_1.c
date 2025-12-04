#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    int value_2 = 0;
    int value_3 = 0;
    
    for(int i=0; i<n; i++){
        if(A[i] % 2 == 0){
            value_2++;
        }
        else if(A[i] % 3 == 0){
            value_3++;
        }
    }
    printf("%d %d", value_2, value_3);
    return 0;
}