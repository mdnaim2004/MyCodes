#include<stdio.h>
int main(){
    int taka;
    scanf("%d", &taka);

    if(taka % 3 == 0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}