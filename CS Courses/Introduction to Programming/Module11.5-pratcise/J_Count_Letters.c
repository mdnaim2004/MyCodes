#include<stdio.h>
#include<string.h>
int main(){
    char s[10000001];
    scanf("%s", s);
    int fre_arr[26] = {0};

    int length = strlen(s);

    for(int i=0; i<length; i++){
        int val = s[i] - 'a';
        fre_arr[val]++;
    }

    for(int i=0; i<26; i++){
        if(fre_arr[i] != 0){
            printf("%c - %d\n", i+'a', fre_arr[i]);
        }
    }
    
    return 0;
}