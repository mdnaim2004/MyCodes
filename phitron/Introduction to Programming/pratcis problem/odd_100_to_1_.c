#include<stdio.h>
int main(){
    for(int i=100; i>=1; i--){
        if(i % 2 == 1){
            printf("odd : %d\n", i);
        }
    }
}