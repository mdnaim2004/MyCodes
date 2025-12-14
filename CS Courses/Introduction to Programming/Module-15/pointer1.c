#include<stdio.h>
int main(){
    int x = 10;
    
    printf(" the value of x = %d\n", x);
    printf(" the pointer of &x = %p\n", &x);

    int *ptr;
    ptr = &x;
    printf(" store in the value of the address of ptr = %p\n", ptr);

    printf(" thr value of address of ptr = %p\n", &ptr);
    return 0;
}