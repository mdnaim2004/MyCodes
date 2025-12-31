#include<stdio.h>
int main(){
    int tk;
    scanf("%d", &tk);

    if(tk > 1000){
        printf("I will buy Punjabi\n");
        if((tk-1000) >= 500){
            printf("I will buy new shoes\n");
            printf("Alisa will buy new shoes\n");
        }
    }
    else{
        printf("Bad luck!\n");
    }
}

// this is a complex problem.....and 3 conditions........