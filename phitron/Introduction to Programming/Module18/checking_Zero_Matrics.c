#include<stdio.h>
int main(){
    int r, c;
    scanf("%d %d", &r, &c);
    int arr[r][c];
    for(int i=0; i<r; i++){
        for(int j=0;j<c; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int total_val = r*c;
    int count = 0;

    for(int i=0; i<r; i++){
        for(int j=0; j<c ; j++){
            if(arr[i][j] == 0){
                count++;
            }
        }
    }
    if(total_val == count){
        printf("this is zero matrix");
    }
    else{
        printf("this is not zero matrix");
    }

    return 0;
}