#include<stdio.h>
int main(){
    int tk;
    scanf("%d", &tk);
    if(tk >= 100){
        printf("burger khabo....");
    }
    else if(tk >= 50){
        printf("fuska khabo.....");
    }
    else if(tk >= 20){
        printf("chips khabo.......");
    }
    else if(tk >= 5){
        printf("choklet khabo.....");
    }
    else{
        printf("i am goribs....");
    }
    return 0;
}