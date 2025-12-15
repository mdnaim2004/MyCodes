#include<stdio.h>
int main(){
    int i=0;
    while(i<=20){
        
        if(i==12){
            break;
        }
        printf("%d\n", i);
        i++;
    }
}