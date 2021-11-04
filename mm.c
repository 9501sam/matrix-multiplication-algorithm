#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "malgo.h"

#define SIZE 1500
#define INIT_VAL (double)1.1

double A[SIZE][SIZE];
double B[SIZE][SIZE];
double C[SIZE][SIZE];

int
main()
{
    int i, j;

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            A[i][j] = INIT_VAL;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            B[i][j] = INIT_VAL;

    clock_t start, end;

    start = clock();
    loop_ijk(SIZE, A, B, C);
    end = clock();
    float seconds_loop_ijk = (float)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    loop_reorder(SIZE, A, B, C);
    end = clock();
    float seconds_loop_reorder = (float)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    matrix_col(SIZE, A, B, C);
    end = clock();
    float seconds_matrix_col = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%f\n", C[100][100]);

    printf("------------------------------\n");
    printf("ijk: %.2lf\n", seconds_loop_ijk);
    printf("reordering: %.2lf\n", seconds_loop_reorder);
    printf("matrix col: %.2lf\n", seconds_matrix_col);
    
    exit(EXIT_SUCCESS);
}
