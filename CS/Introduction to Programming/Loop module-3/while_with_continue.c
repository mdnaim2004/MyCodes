#include<stdio.h>
int main(){
    int i=1; //inmitilization
    while(i<=10){ // consition
        if(i == 6){
            continue;
        }
        printf("%d\n", i);
        i++;  //increment or decrement
    }
    return 0;
}