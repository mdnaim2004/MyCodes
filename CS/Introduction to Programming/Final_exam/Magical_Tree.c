#include<stdio.h>
int main(){
    
    int n; 
    scanf("%d", &n);

    int star = 1;

    int line = (n + 11) / 2;
    int space = line - 1;


    for(int i = 1; i <= line; i++){
        for(int j = 0; j < space; j++){
            printf(" ");
        }
        for(int j = 0; j < star; j++){
            printf("*");
        }
        printf("\n");

        star += 2;
        space--;
    }


    for(int i = 1; i <= 5; i++){
        for(int j = 0; j < 5; j++){
            printf(" ");
        }

        for(int j = 1; j <= n; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
