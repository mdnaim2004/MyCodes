#include<stdio.h>
int main(){
    int n = 200;
    for(int i=1; i<=n; i++){
        int times=8*i;
        printf("8 * %d = %d\n",i, times);
    }
}