
#include<stdio.h>
int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    int a[n];

    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    //or nicher loop er bodole e ami chile amar question e je size ase ta bole dite pari....
    // jemon

    //int fre[1000001] = {0};

    //uporer oi line dile amar ar nicher loop ar deaua lagbe na.

    int fre[m+1]; 
    for(int i=1; i<=m; i++){
        fre[i] = 0;
    }
    
    for(int i=1; i<=n; i++){
        int value = a[i];
        fre[value]++;
    }
    
    for(int i=1; i<=m; i++){
        printf("%d\n", fre[i]);
    }
    return 0;
}