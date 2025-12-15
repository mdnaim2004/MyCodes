// #include<stdio.h>
// int main(){
//     int n;
//     scanf("%d", &n);

//     int arr[n];
//     int rev_arr[n];

//     for(int i=0; i<n; i++){
//         scanf("%d", &arr[i]);
//         rev_arr[i] = arr[i];
//     }

//     int i=0, j=n-1;
//     while (i < j){
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//         i++;
//         j--;
//     }

//     int palindom = 1;
//     for(int i=0; i<n; i++){
//         if(arr[i] != rev_arr[i]){
//             palindom = 0;
//             break;
//         }
//     }

//     if(palindom == 1){
//         printf("YES\n");
//     }
//     else{
//         printf("NO\n");
//     }
    
//     return 0;
// }



//optimal solution

#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int flag = 1;
    int i=0;
    int j=n-1;

    while(i<j){
        if(arr[i] != arr[j]){
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    if(flag ==1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    return 0;
}