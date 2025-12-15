
#include<stdio.h>
#include<string.h>

int is_palindrome(char s[]){
    int length = strlen(s);

    int palindom = 1;
    int i=0, j=length-1;

    while(i<j){
        if(s[i] != s[j]){
            palindom = 0;
            return 0;
        }
        i++;
        j--;
        
    }
    return 1;
}
int main(){

    int n = 1005;
    char s[n];

    scanf("%s", &s);

    int palindom = is_palindrome(s);
    if(palindom == 1){
        printf("Palindrome\n");
    }
    else{
        printf("Not Palindrome\n");
    }
    return 0;
}