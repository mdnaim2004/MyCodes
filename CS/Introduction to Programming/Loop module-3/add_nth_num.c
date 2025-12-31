


//Adding 1 to nth position of all number

#include<stdio.h>
int main(){
    int n;

    scanf("%d", &n);
    
    int sum = 0;

    for(int i=0; i<=n; i++){
        sum = sum + i;
        printf("%d\n", sum);
    }
    printf("The final result is =%d\n", sum);

    return 0;
}