#include<stdio.h>
void function(int n){

    if (n==0){
        return;
    }
    int last_digit = n%10;
    function(n/10);
    printf("%d ", last_digit);
    
    //printf("%d", last_div);
}
int main(){

    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        int n;
        scanf("%d", &n);
        if(n==0){
            printf("0");
        }
        function(n);
        printf("\n");
    }
    
    
    return 0;
}