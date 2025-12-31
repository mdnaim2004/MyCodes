#include<stdio.h>

void fun(int *x){

    *x = 50;
    // printf(" fun function ar value = %d\n", x);

}
int main(){
    int x = 10;
    //printf("Main function ar value = %d\n", x);
    fun(&x);
    printf("%d", x);
    return 0;
}