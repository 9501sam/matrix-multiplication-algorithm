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
    // printf("%.2lf,", seconds);
}

int
main()
{
    printf("------------------------------\n");

    int a[] = {2, 3, 4, 5, 6, 10, 12, 15, 20, 25, 30, 50, 60, 
        75, 100, 125, 150, 250, 300, 375, 500, 750, 1500};

    for (int i = 0; i < 23; i++) {
        BLK_SIZE = a[i];
        printf("\n%d,", BLK_SIZE);
        test_algo(block, "block");
        test_algo(block_copy, "block_copy");
    }

    exit(EXIT_SUCCESS);
}

