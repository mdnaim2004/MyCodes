// #include<stdio.h>
// int main(){
//     //int n = 4;
//     int space = 0;
//     int star = 13;
//     for(int i=1; i<=7; i++){
//         for(int j=1; j<=space; j++){
//             printf(" ");
//         }
//         for(int j=1; j<=star; j++){
//             printf("*");
//         }
//         printf("\n");
//         space++;
//         star-=2;
//     }
//     return 0;
// }



#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    //int star = n;
    int space = (n-1);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=space; j++){
            printf(" ");
        }
        for(int j=i; j>=1; j--){
            printf("%d", j);
        }
        printf("\n");
        //star++;
        space--;
    }
    return 0;
}