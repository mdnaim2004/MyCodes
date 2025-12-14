#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int size;
        scanf("%d", &size);

        int arr[size];  // C-তে VLA allowed

        int target;
        scanf("%d", &target);

        for (int j = 0; j < size; j++) {
            scanf("%d", &arr[j]);
        }

        int flag = 0;

        for (int j = 0; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                for (int l = k + 1; l < size; l++) {
                    int sum = arr[j] + arr[k] + arr[l];
                    if (sum == target) {
                        flag = 1;
                    }
                }
            }
        }

        if (flag == 0) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}
