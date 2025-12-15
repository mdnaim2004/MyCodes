#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int coutnt_0 = 0, coutnt_1 = 0, coutnt_2 = 0,coutnt_3 = 0, coutnt_4 = 0;
    for(int i=0; i<n; i++){

        if(a[i] == 0){
            coutnt_0++;
        }

        else if(a[i] == 1){
            coutnt_1++;
        }

        else if(a[i] == 2){
            coutnt_2++;
        }

        else if(a[i] == 3){
            coutnt_3++;
        }

        else if(a[i] == 4){
            coutnt_4++;
        }
    }
    printf("%d -> %d\n",0, coutnt_0);
    printf("%d -> %d\n",1, coutnt_1);
    printf("%d -> %d\n",2, coutnt_2);
    printf("%d -> %d\n",3, coutnt_3);
    printf("%d -> %d\n",4, coutnt_4);
    return 0;
}