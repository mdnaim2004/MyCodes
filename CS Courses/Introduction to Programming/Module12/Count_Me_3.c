#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d", &n);

    char s[10001];
    for(int i=0; i<n; i++){
        scanf("%s", &s);
        int length = strlen(s);

        int small = 0;
        int capital = 0;
        int num = 0;

        for(int i=0; i<length; i++){
            if(s[i] >= 'a' && s[i] <= 'z' ){
                small++;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z' ){
                capital++;
            }
            else if(s[i] >= '0' && s[i] <= '9' ){
                num++;
            }
        }
        printf("%d %d %d\n", capital, small, num);
    }
    
    // for(int i=0; i<n; i++){
    //     printf("%s\n", s);
    // }

    // for(int i=0; i<length; i++){
    //         if(s[i] >= 'a' && s[i] <= 'z' ){
    //             small++;
    //         }
    //         else if(s[i] >= 'A' && s[i] <= 'Z' ){
    //             capital++;
    //         }
    //         else if(s[i] >= '0' && s[i] <= '9' ){
    //             num++;
    //         }
    //     }

    // for(int i=0; i<n; i++){
    //     printf("%d %d %d\n", small, capital, num);
    // }
    

    return 0;
}