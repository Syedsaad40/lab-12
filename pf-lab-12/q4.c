#include <stdio.h>
#include <limits.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int A[N];
        int freq[10002] = {0};

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            freq[A[i]]++;
        }

        int maxFreq = 0, result = INT_MAX;
        for (int i = 1; i <= 10001; i++) {
            if (freq[i] > maxFreq || (freq[i] == maxFreq && i < result)) {
                maxFreq = freq[i];
                result = i;
            }
        }

        printf("%d\n", result);
    }

    return 0;
}
