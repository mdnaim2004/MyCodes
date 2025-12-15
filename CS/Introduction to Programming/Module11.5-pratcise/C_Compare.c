#include<stdio.h>
#include<string.h>
int main(){
    char a[21], b[21];

    scanf("%s %s", &a, &b);
    int value = strcmp(a,b);

    if(value < 0){
        printf("%s\n", a);
    }
    else if(value > 0){
        printf("%s", b);
    }
    else if(value == 0){
        printf("%s\n", a);
    }
    
    return 0;
}