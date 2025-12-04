#include<stdio.h>
int main(){
    int t,m1, m2, d;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        scanf("%d%d%d", &m1, &m2, &d);
        //printf("%d %d %d\n", m1, m2, d);
        int total_day = (m1 * d)/ (m1+m2);
        int time = d - total_day ;

        printf("%d\n", time);
    }
    // scanf("%d%d%d", &m1, &m2, &d);

    // for(int i=0; i<t; i++){
    //     printf("%d %d %d\n", m1, m2, d);
    // }
    



    // for(int i=0; i<t; i++){
    //     scanf("%d %d %d", &m1, &m2, &d);
    // }

    // for(int i=0; i<t; i++){
    //     printf("%d %d %d\n", m1, m2, d);
    // }


    // for(int i=0; i<t; i++){
    //     int total_day = (m1 * d)/ (m1+m2);
    //     int time = d - total_day ;

    //     printf("%d\n", time[i]);
    // }
    
    return 0;
}



