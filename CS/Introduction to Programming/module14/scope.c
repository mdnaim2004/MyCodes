#include<stdio.h>
int x = 100;  //dlobal variable
void scope(){
    //int x  = 10;
    printf("scope = %d\n", x);
}
int main(){
    scope();
    //int x = 20;
    printf("main = %d\n", x);
    return 0;
}