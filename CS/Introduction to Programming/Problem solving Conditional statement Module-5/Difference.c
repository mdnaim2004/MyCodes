#include<stdio.h>
int main(){
    int A, B, C, D;
    scanf("%d %d %d %d",&A, &B, &C, &D);
    int  X =(A * B) - (C * D);

    printf("Difference = %d\n",X);
    return 0;
}