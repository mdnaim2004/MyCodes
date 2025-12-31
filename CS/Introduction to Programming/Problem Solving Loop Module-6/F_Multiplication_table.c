// #include<stdio.h>
// int main(){
//     int n;
//     scanf("%d", &n);
//     for(int i=1; i<=12; i++){
//         int table = n * i;
//         printf("%d * %d = %d\n", n,i,table);
//     }
//     return 0;
// }

#include<stdio.h>
int main(){
    int n; 
    scanf("%d", &n);
    int i = 1;
    while(i<=12){
        int table = n * i;
        printf("%d * %d = %d\n", n,i,table);
        i++;
    }
    return 0;
}