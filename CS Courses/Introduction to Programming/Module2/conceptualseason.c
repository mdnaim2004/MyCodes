#include<stdio.h>
int main(){
    int age;
    scanf("%d", &age);
    if(age <= 12){
        printf("Kid\n");

    }else if(age <= 17){
        printf("Teenager\n");
    }else{
        printf("Adult\n");
    }
    
    if(age > 18){
        printf("Aligeble vote\n");
    }else{
        printf("Not Aligeble\n");
    }
    return 0;
}