#include<stdio.h>
int main(){
    int x = 10;
    printf("%d\n", x);//value of x
    printf("%p\n", &x);//address of x

    int *ptr;
    ptr = &x;

    
    printf("%p\n", ptr); //address of X value store in pointer variable
    printf("%p\n", &ptr); //address of pointer variable

    *ptr = 200;
    printf("%d\n", x); // change in value of x
    printf("%d\n", *ptr);
    return 0;
}