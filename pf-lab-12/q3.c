#include <stdio.h>
#include <stdlib.h>

void addNumber(float **arr, int *size, int *capacity) {
    if (*size == *capacity) {
        *capacity *= 2;
        *arr = (float *)realloc(*arr, (*capacity) * sizeof(float));
    }
    printf("Enter a number: ");
    scanf("%f", &(*arr)[*size]);
    (*size)++;
}

void displayNumbers(float *arr, int size) {
    printf("Numbers in the array: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void removeLast(float **arr, int *size, int *capacity) {
    if (*size > 0) {
        (*size)--;
        if (*size <= *capacity / 4) {
            *capacity /= 2;
            *arr = (float *)realloc(*arr, (*capacity) * sizeof(float));
        }
    } else {
        printf("Array is empty.\n");
    }
}

int main() {
    int capacity = 4, size = 0, choice;
    float *arr = (float *)malloc(capacity * sizeof(float));

    do {
        printf("\n1. Add Number\n2. Display Numbers\n3. Remove Last Number\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) addNumber(&arr, &size, &capacity);
        else if (choice == 2) displayNumbers(arr, size);
        else if (choice == 3) removeLast(&arr, &size, &capacity);

    } while (choice != 4);

    free(arr);
    return 0;
}
