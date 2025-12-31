#include<stdio.h>
#include<string.h>

void fun(char s[]){
    printf("%s\n", s);
    printf("%d\n", strlen(s));
}


int main(){
    
    char s[10];
    // fget(s);
    scanf("%s", &s);
    fun(s);
    return 0;
}