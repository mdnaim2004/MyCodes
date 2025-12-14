#include<stdio.h>
int main(){
    int r, c;
    scanf("%d %d", &r, &c);
    int arr[r][c];
    for(int i=0; i<r; i++){
        for(int j=0;j<c; j++){
            scanf("%d", &arr[r][c]);
        }
    }

    //row Matrix.....
    // if(r==1){
    //     printf("this is row matrix");
    // }
    // else{
    //     printf("this is not row matrix");
    // }

    //column matrix....   
    // if(c==1){
    //     printf("this is column matrix");
    // }
    // else{
    //     printf("this is not column matrix");
    // } 


    //squre matrix......
    if(r==c){
        printf("this is squre matrix");
    }
    else{
        printf("this is not squre matrix");
    }
    return 0;
}