
// Upper tringle


// #include<stdio.h>
// int main(){
//     int n, star = 1;
//     scanf("%d", &n);
//     for(int i=1; i<=n; i++){  //for printing line
//         for(int j=1; j<=star; j++){  //for printing star
//             printf("*");
//         }
//         printf("\n");
//         star++;
//     }
//     return 0;
// }


// Revers tringle

// #include<stdio.h>
// int main(){
//     int n, star=5;
//     scanf("%d", &n);
//     for(int i=1; i<=n; i++){// for printing line 
//         for(int j=1; j<=star; j++){//for printing star
//             printf("*");
//         }
//         printf("\n");
//         star--;
//     }
//     return 0;
// }

#include<stdio.h>
int main(){
    int n, star = 1, rev_star = 4;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=star; j++){
            printf("*");
        }
        printf("\n");
        star++;
    }
    for(int i=1; i<n; i++){
        for(int j=1; i<=rev_star; j++){
            printf("*");
        }
        printf("\n");
        rev_star--;
    }
    return 0;
}