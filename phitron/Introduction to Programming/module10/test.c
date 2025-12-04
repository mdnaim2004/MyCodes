// #include<stdio.h>
// #include<string.h>
// int main(){
//     char s[10]; //ses er akta ghor null charecter er jonne.
//     gets(s);
//     printf("%s", s); // aker odhik line print korte pare na.just enter porjonto.
//     return 0;
// }


// #include<stdio.h>
// int main(){
//     char str[20] = "HELLO\0WORLD";

//     printf("%s", str);


//     return 0;
// }


#include<stdio.h>
int main(){
    char str[20];
    scanf("%c", &str);
    printf("%s", str);
    return 0;
}