#include<stdio.h>
int main(){
    int num;
    scanf("%d", &num);
    if(num > 0){
        printf("The number is POSITIVE");
    }else if(num < 0){
        printf("The number is NEGITIVE");
    }else{
        printf("The num is ZERO");
    }
}