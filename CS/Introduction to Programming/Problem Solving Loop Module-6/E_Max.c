
// maximum

#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    scanf("%d", &n);
    int max = INT_MIN;
    for(int i=1; i<=n; i++){
        int value;
        scanf("%d", &value);
        if(value > max){
            max = value;
        }
        
    }
    printf("%d\n", max);
    return 0;
}


// minimum


// #include<stdio.h>
// #include<limits.h>
// int main(){
//     int n;
//     scanf("%d", &n);
//     int min = INT_MAX;
//     for(int i=1; i<=n; i++){
//         int value;
//         scanf("%d", &value);
//         if(value < min){
//             min = value;
//         }
//     }
//     printf("%d\n", min);
//     return 0;
// }