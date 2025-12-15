
#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    long long int a, b, c;
    long long int ans;
    for(int i=1; i<=n; i++){
        scanf("%lld %lld %lld %lld", &ans, &a, &b, &c);
        
        long long int mul = a * b * c;
        long long int find = ans / mul;

        if(ans % mul == 0){
            printf("%lld\n", find);
        }
        else{
            printf("-1\n");
        }
    }

    return 0;
}