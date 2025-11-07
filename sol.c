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
    int **matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
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
        if (matrix[i][2-1] < ans2) {
            ans2 = matrix[i][2-1];
            pos = i;
        }
    }
    matrix[pos][2-1] = matrix[3-1][4-1];
    matrix[3-1][4-1] = ans2;
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
