// #include<stdio.h>
// int main(){
//     int t;
//     scanf("%d", &t);
//     if(t == 0){
//         printf("0\n");
//     }
//     for(int i=1; i<=t; i++){
//         int n;
//         scanf("%d", &n);
//         for( ;n != 0; ){
//             printf("%d ", n % 10);
//             n = n / 10;
//         }
//         printf("\n");
//     }
//     return 0;
// }

#include<stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        int n;
        scanf("%d", &n);
        do{
            printf("%d ", n%10);
            n = n / 10;
        }while(n != 0);
        printf("\n");
    }
    return 0;
}