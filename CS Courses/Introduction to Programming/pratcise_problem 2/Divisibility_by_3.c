#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", &s);

    int digit = 0;
    for(int i=0; i<n; i++){
        digit = digit + s[i] - '0';
    }

    if(digit % 3 ==0){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}