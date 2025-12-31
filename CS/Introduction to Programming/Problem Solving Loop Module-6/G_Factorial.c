#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);  // number of test cases

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        long long int fact = 1;
        for (int j = 1; j <= n; j++) {
            fact *= j;
        }

        printf("%lld\n", fact);
    }

    return 0;
}
