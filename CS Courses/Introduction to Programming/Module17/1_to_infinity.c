// aita akta infinity loop ar moto kaj korbe.. mane aikhene function k call kora hoinai...|
// ar recurtion ar properti holo function bar bar call kora... 
// ti akheneo same vabe function bar bar call korbe 
// and file size boro hobbe 
// and ak somoy stack memory full hoye jabe......


// #include<stdio.h>

// void count(int i){
//     printf("%d\n",i);
//     count(i+1);
// }


// int main(){
//     int i=1;
//     count(i);
//     return 0;
// }


// oi code ar optimiz solution holo.... function ta ke bar bar call kora theke biroto rakha....
// #include<stdio.h>

// void count(int i){
//     if(i == 21){  // ai if bloca ar maddhome  ami function ke bar bar call kora theke biroto rakhteche....
//         return;
//     }
//     printf("%d ", i);
//     count(i+1);
// }

// int main(){
//     int i=1;
//     count (i);
//     return 0;
// }


#include<stdio.h>

void count(int i){
    if(i == 10){
        return;
    }
    printf("%d ", i);
    count(i + 1);

}
int main(){
    int i = 1;
    count(i);
    return 0;
}