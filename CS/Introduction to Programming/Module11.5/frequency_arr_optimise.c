#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    // int coutnt_0 = 0, coutnt_1 = 0, coutnt_2 = 0,coutnt_3 = 0, coutnt_4 = 0;
    int fre[6] = {0};
    for(int i=0; i<n; i++){

        // if(a[i] == 0){
        //     fre[0]++;
        // }

        // else if(a[i] == 1){
        //     fre[1]++;
        // }

        // else if(a[i] == 2){
        //     fre[2]++;
        // }

        // else if(a[i] == 3){
        //     fre[3]++;
        // }

        // else if(a[i] == 4){
        //     fre[4]++;
        // }

        int val = a[i];
        fre[val]++;
    }
    // printf("%d -> %d\n",0, fre[0]);
    // printf("%d -> %d\n",1, fre[1]);
    // printf("%d -> %d\n",2, fre[2]);
    // printf("%d -> %d\n",3, fre[3]);
    // printf("%d -> %d\n",4, fre[4]);

    for(int i=0; i<6; i++){
        printf("%d --> %d\n", i, fre[i]);
    }
    return 0;
}