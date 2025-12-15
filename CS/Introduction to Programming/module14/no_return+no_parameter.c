#include<stdio.h>

void sum(){
    int a,b;
    scanf("%d %d", &a, &b);
    int val = a+b;
    printf("sum = %d\n", val);
}
void mul(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    int val2 = a*b*c;
    printf("multi = %d\n", val2);
}
int main(){
    sum();
    mul();
    return 0;
}