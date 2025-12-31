#include<stdio.h>
int main(){
    char a[101];
    char b[101];

    scanf("%s %s", &a, &b);
    int length = strlen(b);

    for(int i=0; i <= length; i++){
        a[i] = b[i];
    }
    printf("%s", a);
    return 0;
}