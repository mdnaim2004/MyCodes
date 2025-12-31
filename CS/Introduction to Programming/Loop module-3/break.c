#include<stdio.h>
int main(){
    int n = 10;
    for(int i = 1; i<=n; i++){
        if(i == 6){
            continue;  // continue statement usin one time break the position....
        }
        printf("%d\n", i);
    }
}