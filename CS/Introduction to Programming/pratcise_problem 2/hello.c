#include<stdio.h>
int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    int sum = x+y;
    int sub = x-y;
    int mul = x*y;
    int div = x/y;

    printf("%d %d %d %d", sum, sub, mul, div);

    return 0;
}