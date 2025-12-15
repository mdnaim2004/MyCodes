// #include<stdio.h>
// int main(){
//     char s[100];
//     scanf("%s", &s);

//     printf("%s\n", s);

//     //printf("%d", s[0]);
//     //printf("%d", s[5]);
//     //printf("%s", s[5]);
//     //printf("%s", s[10]);
//     printf("%d", s[10]);
//     return 0;
// }



// #include<stdio.h>
// int main(){
//     char s[100];
//     scanf("%s", &s);
    
//    printf("%s\n", s);

//     printf("%d", s[0]);
//     printf("%d", s[5]);
//     printf("%s", s[5]);
//     printf("%s", s[10]);
//     printf("%d", s[3]);
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     char s[4];
//     scanf("%s", &s);

//     printf("%s", s);

//     return 0;
// }


//normal scanf
// #include<stdio.h>
// int main(){
//     char s[10];
//     scanf("%s", &s);
//     printf("%s", s);
//     return 0;
// }

//gets
#include<stdio.h>
#include<string.h>
int main(){
    char s[10]; //ses er akta ghor null charecter er jonne.
    gets(s);
    printf("%s", s); // aker odhik line print korte pare na.just enter porjonto.
    return 0;
}

//fgets
// #include<stdio.h>
// int main(){
//     char s[100];
//     fgets(s,100,stdin);//ses er akta ghor null charecter er jonne.
//     printf("%s",s);//ses e akta line print korte pare, mane akta line print kore enter o print korte pare er por theme jai.
//     return 0;
// }