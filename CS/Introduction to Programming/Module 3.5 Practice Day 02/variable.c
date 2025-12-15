#include<stdio.h>
int main(){
    int A;
    long long int B;
    double C;
    char D;

    scanf("%d %lld %lf %c", &A, &B, &C, &D);
    printf("%d\n%lld\n%.4lf\n%c\n",A,B,C,D);
    return 0;
}