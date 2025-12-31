#include<stdio.h>
int main(){
    int num;
    scanf("%d", &num);// enter input number
    if(num % 2 == 0){
        printf("EVEN");
    }
    else{
        printf("ODD");
    }
    return 0;
}