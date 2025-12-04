#include<stdio.h>
void sum(int a, int b){
    int val = a+b;
    printf("sum = %d\n", val);
}
void mul(int a, int b, int c){
    int val2 = a*b*c;
    printf("mul = %d\n", val2);
}
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    sum(a, b);
    mul(a, b, c);
    return 0;
}