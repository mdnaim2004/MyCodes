// #include<stdio.h>
// #include<string.h>

// int main(){
//     int n;
//     scanf("%d", &n);
//     char s[];
//     for(int i=0; i<n; i++){
//         scanf("%s", &s);
//         int length = strlen(s);

//         if(length >= 10){
//             printf("%c%d%c\n", s[0], length-2, s[length-1]);
//         }else{
//             printf("%s\n", s);
//         }
//     }
//     return 0;
// }


// #include<stdio.h>
// #include<string.h>
// int main(){
//     int n;
//     scanf("%d", &n);
//     char s[n];
//     for(int i=0; i<n; i++){
//         scanf("%c", &s[i]);
//     }

//     int length = strlen(s);
//     int i=0;
//     while(length >= 10){
//         scanf("%s", &s);
//         int length = strlen(s);

//         if(length >= 10){
//             printf("%c%d%c\n", s[0], length-2, s[length-1]);
//         }else{
//             printf("%s\n", s);
//         }
//         i++;
//     }
//     return 0;
// }



#include<stdio.h>
#include<string.h>

int main() {
    int n;
    char s[100]; // Assuming max length of the string is 100
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int b = strlen(s);

        if (b > 10) {
            printf("%c%d%c\n", s[0], b-2, s[b-1]); // Way too long words Codeforces solution in C
        } else {
            printf("%s\n", s);
        }
    }
    return 0;
}