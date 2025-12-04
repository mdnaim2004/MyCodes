#include<stdio.h>
#include<string.h>
int main(){
    char s[10001];
    scanf("%s", s);
    int small[26] = {0};

    int length = strlen(s);

    for(int i=0; i<length; i++){
        int val = s[i] - 'a';
        small[val]++;
    }

    for(int i=0; i<26; i++){
        if(small[i] != 0){
            printf("%c - %d\n", i+'a', small[i]);
        }
    }
    
    return 0;
}