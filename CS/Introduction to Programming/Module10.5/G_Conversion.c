#include<stdio.h>
int main(){
    int n = 100005;
    char s[n];

    scanf("%s", &s);

    int i=0;
    while(s[i] != '\0'){
        if(s[i] == ','){
            s[i] = ' ';
        }
        else if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i] - 32;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + 32;
        }
        i++;
    }
    printf("%s", s);
    // char s =' a';
    // printf("%d", s);

    return 0;
}