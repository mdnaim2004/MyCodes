#include<stdio.h>
#include<string.h>
int main(){
    
    char A[22];
    char B[22];

    scanf("%s %s", &A, &B);
    int length_A = strlen(A);
    int length_B = strlen(B);

    printf("%d %d\n", length_A, length_B);
    //char c[22];
    printf("%s%s\n", A, B);

    char temp = A[0];
    A[0] = B[0];
    B[0] = temp;
    printf("%s %s\n", A, B);
    return 0;
}