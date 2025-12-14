#include<stdio.h>
int main(){
    int A = 10;
    int B = 20;

    int temp = A;
    A = B;
    B = temp;

    printf("A = %d\n", A);
    printf("B = %d\n", B);

    return 0;
}