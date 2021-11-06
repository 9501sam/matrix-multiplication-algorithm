#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "malgo.h"

#define SIZE 1500
#define INIT_VAL (double)1.1

double A[SIZE][SIZE];
double B[SIZE][SIZE];
double C[SIZE][SIZE];

void
matrix_init()
{
    int i, j;

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            A[i][j] = INIT_VAL;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            B[i][j] = INIT_VAL;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            C[i][j] = 0;
}

typedef void (*malgo)(int n, double A[n][n], double B[n][n], double C[n][n]);

void 
test_algo(malgo algo, const char *algo_name)
{
    matrix_init();

    clock_t start, end;
    float seconds;

    start = clock();
    algo(SIZE, A, B, C);
    end = clock();

    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("%s: %.2lf sec\n", algo_name, seconds);
}

int
main()
{
    printf("------------------------------\n");

    test_algo(loop_ijk, "loop_ijk");
    test_algo(loop_reorder, "loop_reorder");
    test_algo(matrix_col, "matrix_col");
    test_algo(block, "block");
    test_algo(block_copy, "block_copy");

    exit(EXIT_SUCCESS);
}

