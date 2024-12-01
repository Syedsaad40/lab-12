#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int *size, int value, int position) {
    if (*size == 0) {
        *arr = (int *)malloc(sizeof(int));
        (*arr)[0] = value;
        (*size)++;
        return;
    }
    
    if (*size == position) {
        *arr = (int *)realloc(*arr, (*size + 1) * sizeof(int));
        (*arr)[*size] = value;
        (*size)++;
        return;
    }

    *arr = (int *)realloc(*arr, (*size + 1) * sizeof(int));
    for (int i = *size; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[position] = value;
    (*size)++;
}

void delete(int **arr, int *size, int position) {
    if (*size == 0 || position >= *size) return;

    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    *arr = (int *)realloc(*arr, (*size - 1) * sizeof(int));
    (*size)--;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N;
        scanf("%d", &N);

        int *arr = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        
        int value, position;
        char op;

        while (scanf(" %c", &op) == 1) {
            if (op == 'I') {
                scanf("%d %d", &value, &position);
                insert(&arr, &N, value, position);
            } else if (op == 'D') {
                scanf("%d", &position);
                delete(&arr, &N, position);
            }

            for (int i = 0; i < N; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        free(arr);
    }
    
    return 0;
}
