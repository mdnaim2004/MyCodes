#include<stdio.h>
int main(){
    char s;
    scanf("%s", &s);
   
    if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u'){
        printf("Vowel\n");
    }
    else{
        printf("Consonant\n");
    }

    return 0;
}