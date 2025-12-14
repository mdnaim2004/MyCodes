#include<stdio.h>

void count(int i){
    if(i == 100){
        return;
    }
    if(i % 2 == 0){
        printf("the odd num = %d ", i);
        
    }
   
    else{
        printf("the even number = %d ", i);
    }
    count(i + 1);
}
int main(){
    int i = 1;
    count(i);
    return 0;
}