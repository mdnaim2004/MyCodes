#include<stdio.h>
#include<string.h>
int main(){
    char a[101];
    char b[101];

    scanf("%s %s", &a, &b);
    int length = strlen(b);

    strcpy(b , a); ///akhene a mane a te copy kore rakhbo 
                    // b ke copy korbo

    // for(int i=0; i <= length; i++){
    //     a[i] = b[i];
    // }
    printf("%s", a);
    return 0;
}