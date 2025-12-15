//sudhu varisble hobbr na.
//karon variable passs by value hisabe hoy 

// #include<stdio.h>

// int fun(int *x){
//     x = 200;
//      printf("%d\n", *x);
// }
// int main(){
//     int x = 100;
//     fun(x);

//     printf("%d", x);
   
//     return 0;
// }

//same jinish jodi amra Array ar jonne kori tahole ai rokom hobbe
//fun function ar vitor jodi kichu change kori tahole man function e thaka obostai amra dekhte pabo
#include<stdio.h>

void fun(int arr[]){
    arr[1] = 200;
}

int main(){

    int arr[5] = {10,20, 30, 40, 50};

    fun(arr);

    for(int i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
// summary holo amra jokhon kono variable dei tokhon seita by default pass by value hisabe pass hoy 
//ar jokhon amra Array dei tokhon pass by refefence hisabe pass hoy.