#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        // Sort the array in ascending order
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }

        // Find the starting index of elements greater than k
        int st = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > k) {
                st = i;
                break;
            }
        }

        // Reduce elements in pairs until the condition is met
        for (int i = st; i < n - 1; i++) {
            while (k < a[i] && k < a[i + 1]) {
                a[i]--;
                a[i + 1]--;
            }
        }

        // Calculate the sum of the array
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i];
        }

        printf("%d\n", ans);
    }

    return 0;
}