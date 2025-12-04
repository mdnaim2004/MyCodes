#include<stdio.h>
int main(){
    int taka;
    scanf("%d", &taka);
    for(int i=1; i<=taka; i++){
        if(i % 3 == 0 ){
            printf("%d Yes\n", i);
        }
        else if(i % 5 == 0){
            printf("%d Yes\n", i);
        }
        else{
            printf("%d No\n", i);
        }
    }
    return 0;
}