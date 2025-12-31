#include<stdio.h>
int main(){
    char ch;
    scanf("%c", &ch);
    

    if(ch >= 'a' && ch < 'z'){
        ch++;
        printf("%c\n", ch);
    }
    else if( ch == 'z'){
        printf("a\n");
    }
    
    

    return 0;
}

//next alphabet problem