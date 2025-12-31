


// this problem statement is make a simple calculator


#include<stdio.h>
int main(){
    int x,y;
    scanf("%d %d", &x, &y);
    int sum = x + y;
    long long int mul = (long long int)x * y;
    int sub = x - y;

    printf("%d + %d = %d\n", x, y, sum);
    printf("%d * %d = %lld\n", x, y, mul);
    printf("%d - %d = %d\n", x, y, sub);
    return 0;
}