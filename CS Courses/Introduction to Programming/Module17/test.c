// #include<stdio.h>
// void gello(){
//     printf("gello");
// }
// void hello(){
//     gello();
//     printf("hello");
// }
// int main(){
//     printf("main");
//     hello();
//     return 0;
// }

#include<stdio.h>
void f2(){
    printf("f1");
}
void f1(){
    printf("f2");
    f2();
}
int main(){
    printf("Main ");
    f1();
    return 0;
}