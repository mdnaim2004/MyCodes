


// this problem calculate first digit
#include<stdio.h>
int main(){
    int X, num;
    scanf("%d", &X);
    num = X/1000;

    if(num % 2 == 1){ // 
        printf("ODD\n");
    }
    else{
        printf("EVEN\n");
    }
    return 0;
}