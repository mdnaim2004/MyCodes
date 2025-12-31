

// Find minimum and maximum into a three integers value


#include<stdio.h>
int main(){
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    if(A <= B && A <= C){
        printf("%d ", A);
    }
    else if(B <= A && B <= C){
        printf("%d ", B);
    }
    else if(C <= A && C <= B){
        printf("%d ",C);
    }
    

    //maximum
    if(A >= B && A >= C){
        printf("%d", A);
    }
    else if(B >= A && B >= C){
        printf("%d", B);
    }
    else if(C >= A && C >= B){
        printf("%d",C);
    }
    return 0;
}