#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int target;
    scanf("%d", &target);

    int flag = 0;// flag variable use kora hoy jodi condition true na hoy tahole nestade loop er vitor onekgulo NO print hobbe

    for(int i=0; i<n-1; i++){

        for(int j=i+1; j<n; j++){

            //printf("%d %d\n", arr[i], arr[j]);

            if(arr[i] + arr[j] == target){
                flag = 1; //ti akhene ai conditin ar jonne akhene flag variable use kore akhene flag ar man 1 kore deaua hoy 
                printf("Yes\n");
            }
            // else{
            //     printf("No\n");
            // }
        }
        
    }
    if(flag == 0){ // jodi uporer nestade loop ar condition true na hoy tokhon aita true hobbe and NO print korobe....

        printf("No\n");
    }

    return 0;
}
//flag variable use kora hoy muloto true false korer jonne
//1st e flag er man set kora hoy , then niyom onujaie loop use kora jai, than then condition use kore tar vitor flag er man poriborton kora hoy. 
//ar por jodi nestade loop er condition thik hoy tahole flag ar man change hoy,
// ar por niche ase aber condition check kora hoy je flag ar man chenge hoiche ki na 
// ar niche condition ar vito NO print kore deaua hoy