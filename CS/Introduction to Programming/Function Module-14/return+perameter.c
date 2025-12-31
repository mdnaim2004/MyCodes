#include<stdio.h>

int sum(int a, int b){
    int val = a+b;
    return val;
}
int sub(int a, int b){
    int val2 = a-b;
    return val2;
}
int mul(int a, int b){
    int val3 = a*b;
    return val3;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    int val = sum(a, b); //call sum function
    int val2 = sub(a, b);//call sub function
    int val3 = mul(a, b);//call mul function

    printf("%d + %d = %d\n", a, b, val);
    printf("%d - %d = %d\n", a, b, val2);
    printf("%d * %d = %d\n", a, b, val3);
    return 0;
}