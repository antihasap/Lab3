#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        return 1;
    }
    int n, m;
    fscanf(file, "%d %d", &n, &m);
    if (n <= 0 || m <= 0) {
        fclose(file);
        return 1;
    }
    int **matrix = (int**)malloc(n * sizeof(int*));
    if (matrix == NULL) {
        fclose(file);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            fclose(file);
            return 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
    int ans1 = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + j < n - 1) {
                if (matrix[i][j] > 0) {
                    ans1 *= matrix[i][j];
                }
            }
        }
    }
    int ans2 = 100000000, pos = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[i][1] < ans2) {
            ans2 = matrix[i][1];
            pos = i;
        }
    }
    matrix[pos][1] = matrix[2][3];
    matrix[2][3] = ans2;
    printf("%d", ans1);
    printf("%d \n", ans2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
