

//find odd even

#include<stdio.h>
int main(){
    int n;
    n = 20;

    for( int i=0; i<=n; i++){ // 
        if(i % 2 == 0){
            printf("%d -- EVEN Number\n", i);
        }else{
            printf("%d -- ODD Number\n", i);
        }
    }
    return 0;
}