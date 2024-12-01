#include <stdio.h>
#include <stdlib.h>

int main() {
    int numStudents, *numGrades, i, j;
    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    numGrades = (int *)malloc(numStudents * sizeof(int));
    int **grades = (int **)malloc(numStudents * sizeof(int *));

    for (i = 0; i < numStudents; i++) {
        printf("Enter number of grades for student %d: ", i + 1);
        scanf("%d", &numGrades[i]);
        grades[i] = (int *)malloc(numGrades[i] * sizeof(int));
        for (j = 0; j < numGrades[i]; j++) {
            printf("Enter grade %d for student %d: ", j + 1, i + 1);
            scanf("%d", &grades[i][j]);
        }
    }

    printf("\nGrades:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Student %d: ", i + 1);
        for (j = 0; j < numGrades[i]; j++) {
            printf("%d ", grades[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < numStudents; i++) {
        free(grades[i]);
    }
    free(grades);
    free(numGrades);

    return 0;
}
