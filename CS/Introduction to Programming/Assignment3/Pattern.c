#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    
    int space = n-1;
    int symbol = 1;

    for(int i=1; i<= (2*n) - 1; i++){
        for(int j=1; j<= space; j++){
             printf(" ");
        }
        if(i % 2== 1){
            for(int j=1; j<= symbol; j++){
                printf("#");
            }
            
        }
        else{
            for(int j=1; j<= symbol; j++){
                printf("-");
            }
        }
       
        if(i <= n-1){
            space--;
            symbol +=2;
        }
        else{
            space++;
            symbol -=2;
        }
        printf("\n");
    }
    
    return 0;
}



//  for(int j=1; j<= space; j++){
//             printf(" ");
//         }
//         for(int j =1; j<=symbol; j++){
//             if(j % 2 ==0){
//                 printf("#");
//             }
//             else{
//                 printf("-");
//             }
//         }
//     }
// }