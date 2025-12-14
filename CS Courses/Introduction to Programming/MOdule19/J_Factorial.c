#include<stdio.h>

long long int fact(int n){
    if(n == 1){
        return 1;
    }
    long long int mul = fact(n-1);
    return n*mul;
}
int main(){
    int n;
    scanf("%d", &n);
    long long int ans = fact(n);
    printf("%lld", ans);
    return 0;
}