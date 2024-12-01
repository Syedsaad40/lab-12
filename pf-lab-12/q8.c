#include <stdio.h>
#include <stdlib.h>

int main() {
    int numPoints;
    float *fees, totalProfit = 0;
    printf("Enter the total number of points: ");
    scanf("%d", &numPoints);
    if (numPoints <= 0) {
        printf("Error: The number of points must be positive.\n");
        return 1;
    }
    fees = (float *)malloc(numPoints * sizeof(float));
    if (fees == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < numPoints; i++) {
        printf("Enter the fee for point %d: ", i + 1);
        scanf("%f", &fees[i]);
        if (fees[i] < 0) {
            printf("Error: Fee cannot be negative. Please enter a valid fee.\n");
            free(fees);
            return 1;
        }

        totalProfit += fees[i]; 
    }
    printf("Total profit generated: %.2f\n", totalProfit);
    free(fees);

    return 0;
}
