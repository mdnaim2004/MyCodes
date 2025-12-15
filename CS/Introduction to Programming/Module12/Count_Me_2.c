#include<stdio.h>
#include<string.h>
int main(){
    char s[100001];
    scanf("%s", &s);

    //int fre_arr[26] = {0};

    int length = strlen(s);


    //char vowel[5] = {'a','e', 'i', 'o', 'u'}; 
    int value = 0;

    for(int i=0; i<length; i++){


        if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
            value++;
        }
        // if(s[i] !=vowel ){
        //     value++;
        // }
        
    }

    printf("%d\n", value);

    
    return 0;
}