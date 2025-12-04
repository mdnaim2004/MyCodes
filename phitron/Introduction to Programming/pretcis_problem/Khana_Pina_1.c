#include<stdio.h>
int main(){
    int taka;
    scanf("%d", &taka);

    if(taka >=1000){
        printf("Three Kacchi\n");
    }
    else if(taka >= 500){
        printf("One Large Pizza\n");
    }
    else if(taka >= 250){
        printf("Three Small Burger\n");
    }
    else if(taka >= 100){
        printf("Three Fuchka\n");
    }
    else{
        printf("Nothing\n");
    }
    return 0;
}