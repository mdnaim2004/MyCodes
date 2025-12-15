#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){

        for(int j=i+1; j<n; j++){

            //ascending orde

            // if(arr[i] > arr[j]){   //ai condition ar vitor ami jodi > ar jaigei < use kori tahole aita desending order hobbbe

            //     int temp = arr[i];
            //     arr[i] = arr[j];
            //     arr[j] = temp;

            // }

            //descending order
            if(arr[i] < arr[j]){   //ai condition ar vitor ami jodi > ar jaigei < use kori tahole aita desending order hobbbe

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}