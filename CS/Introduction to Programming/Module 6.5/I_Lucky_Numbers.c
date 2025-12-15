#include<stdio.h>
int main(){
    int a;
    scanf("%d", &a);

    int div = a/10;
    int rem = a%10;

    if(rem == 0){
        printf("YES\n");
    }
    else if(div % rem ==0 || rem % div == 0){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    return 0;
}