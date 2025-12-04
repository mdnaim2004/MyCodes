
#include<stdio.h>

int main(){
    int r, c;
    scanf("%d %d", &r, &c);

    int arr[r][c];

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}






// #include<stdio.h>
// int main(){
//     int r, c;
//     scanf("%d %d", &r, &c);
//     int arr[r][c];

//     scanf("%d", &arr[0][0]);
//     scanf("%d", &arr[0][1]);
//     scanf("%d", &arr[0][2]);
//     scanf("%d", &arr[1][0]);
//     scanf("%d", &arr[1][1]);
//     scanf("%d", &arr[1][2]);
//     scanf("%d", &arr[2][0]);
//     scanf("%d", &arr[2][1]);
//     scanf("%d", &arr[2][2]);
    
//     printf("%d ", arr[0][0]);
//     printf("%d ", arr[0][1]);
//     printf("%d\n", arr[0][2]);
//     printf("%d ", arr[1][0]);
//     printf("%d ", arr[1][1]);
//     printf("%d\n", arr[1][2]);
//     printf("%d ", arr[2][0]);
//     printf("%d ", arr[2][1]);
//     printf("%d\n", arr[2][2]);

//    return 0;
// }
