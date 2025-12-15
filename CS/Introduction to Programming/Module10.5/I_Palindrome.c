#include<stdio.h>
#include <string.h>
int main(){

    int n = 1005;
    char s[n];

    scanf("%s", &s);

    int length = strlen(s);

    int palindom = 1;
    int i=0, j=length-1;

    while(i<j){
        if(s[i] != s[j]){
            palindom = 0;
            break;
        }
        i++;
        j--;
    }
    if(palindom == 1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    return 0;
}


// #include<stdio.h>
// #include<string.h>

// int main()
// {
//     int N = 1005;
//     char str[N];

//     scanf("%s", &str);

//     int length = strlen(str);

//     int flag = 1;
//     int left = 0, right = length - 1;

//     while(left < right)
//     {
//         if (str[left] != str[right]) {
//             flag = 0;
//             break;
//         }
//         left++, right--;
//     }

//     if (flag == 1) {
//         printf("YES");
//     } else {
//         printf("NO");
//     }



// }