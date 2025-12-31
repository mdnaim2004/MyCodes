
//the priblem statement is conditional statement type problem
#include<stdio.h>
int main(){
    char ch;
    scanf("%c", &ch);

    if(ch >= '0' && ch <= '9'){
        printf("IS DIGIT\n");
    }
    else{
        printf("ALPHA\n");
        if(ch >= 'A' && ch <= 'Z'){
            printf("IS CAPITAL\n");
        }
        else{
            printf("IS SMALL\n");
        }
    }

    return 0;
}