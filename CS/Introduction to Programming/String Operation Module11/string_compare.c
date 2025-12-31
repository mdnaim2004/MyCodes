#include<stdio.h>
int main(){
    char a[101], b[101];
    scanf("%s %s", &a, &b);

    int i=0;
    while(1){
        if(a[i] == '\0' && b[i] == '\0'){
            printf("Equal");
            break;
        }
        else if(a[i] == '\0'){
            printf("A is small");
            break;
        }
        else if(b[i] == '\0'){
            printf("B is small\n");
            break;
        }
        else if(a[i] < b[i]){
            printf("A is small");
            break;
        }
        else if(b[i] < a[i]){
            printf("B is small");
            break;
        }
        else if(a[i] == b[i]){
            i++;
        }
    }
    return 0;
}