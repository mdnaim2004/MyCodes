#include <stdio.h>

int main() {
    int row, space, star;

    /* ----- Upper Part ----- */
    for (row = 1; row <= 4; row++) {
        for (space = 1; space <= 8 - row; space++)
            printf(" ");
        
        for (star = 1; star <= row; star++)
            printf("* ");
        
        printf("\n");
    }

    /* ----- Lower Part ----- */
    for (row = 1; row <= 3; row++) {
        for (space = 1; space <= 4 + row; space++)
            printf(" ");
        
        for (star = 1; star <= 4 - row; star++)
            printf("* ");
        
        printf("\n");
    }

    return 0;
}
