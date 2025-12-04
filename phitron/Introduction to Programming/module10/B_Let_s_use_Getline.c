#include<stdio.h>
#include<string.h>
int main(){
    char s[1000005];
    // fgets(s,1000005,stdin);
    gets(s);

    int length = strlen(s);
    
    for(int i=0; i<length; i++){
        if (s[i] == '\\'){
            s[i] = '\0';
            break;
        }
    }
    printf("%s\n", s);
    
    
    return 0;
}