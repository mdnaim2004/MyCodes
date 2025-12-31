#include<stdio.h>
int sum(int x, int y){
    int val = x+y;
    return val;
}
int main(){
    printf("%d\n", sum(5,6));
    return 0;
}