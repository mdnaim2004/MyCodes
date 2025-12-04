#include<stdio.h>
int main(){
    char ch;
    scanf("%c", &ch);

    if(ch >= 'A' && ch <= 'Z'){
        ch = ch + 32;
        printf("%c\n", ch);
    }
    else{
        ch = ch - 32;
        printf("%c\n", ch);
    }


    return 0;
}



// #include<stdio.h>
// int main(){
//     char ch = 'A';
//     printf("%c", ch+1+1+1);
//     return 0;
// }
// #include<stdio.h>
// int main(){
//     int num = 66;
//     printf("%c", num);
//     return 0;
// }