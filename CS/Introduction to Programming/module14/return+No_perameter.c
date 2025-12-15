#include<stdio.h>
int sum(){
    int a, b;
    scanf("%d %d", &a, &b);
    int val = a+b;
    return val;
}
int main(){
    
    int val = sum();
    printf("%d",  val);

    return 0;
} 