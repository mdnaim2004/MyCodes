#include<stdio.h>

void hello(int i){
    if(i == 8){
        return;
    }
    hello(i+1);
    printf("%d ", i);
}
int main(){
    hello(1);
    return 0;
}