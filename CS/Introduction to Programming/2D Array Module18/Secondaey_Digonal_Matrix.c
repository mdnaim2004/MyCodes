#include<stdio.h>
int main(){
    int r, c;
    scanf("%d %d", &r,&c);
    int arr[r][c];

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int is_digonal = 100;

    if(r == c){ //squre matrix
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(i + j == r-1){
                    //we are inside in digonal
                    // printf("%d %d\n", i, j);
                }
                else{
                    //we ara outside in digonal
                    if(arr[i][j] != 0 ){
                        is_digonal = 200;
                        printf("This is not a Secondary digonal matrix");
                        break;
                        
                    }
                }
            }
        }
        if(is_digonal == 100){
            printf("This is Secondary Digonal Matrix");
        }  
    }
    
    else{
        printf("this is not squre matrix");
    }
    return 0;
}