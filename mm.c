#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <getopt.h>
#include <stdbool.h>
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

    assert(1814.00 < C[123][456] && C[123][456] < 1816.00);

    printf("%s: %.2lf sec\n", algo_name, seconds);
}

int
main(int argc, char *argv[])
{
    int opt;
    bool algo_flag[6] = {false, false, false, false, false, false};
    while ((opt = getopt(argc, argv, ":12345a")) != -1) {
        switch (opt) {
        case '1':
            algo_flag[1] = true;
            break;
        case '2':
            algo_flag[2] = true;
            break;
        case '3':
            algo_flag[3] = true;
            break;
        case '4':
            algo_flag[4] = true;
            break;
        case '5':
            algo_flag[5] = true;
            break;
        case 'a':
            algo_flag[1] = true;
            algo_flag[2] = true;
            algo_flag[3] = true;
            algo_flag[4] = true;
            algo_flag[5] = true;
            break;
        }
    }

    printf("------------------------------\n");
    if (algo_flag[1])
        test_algo(loop_ijk, "loop_ijk");
    if (algo_flag[2])
        test_algo(loop_reorder, "loop_reorder");
    if (algo_flag[3])
        test_algo(matrix_col, "matrix_col");
    if (algo_flag[4])
        test_algo(block, "block");
    if (algo_flag[5])
        test_algo(block_copy, "block_copy");

    exit(EXIT_SUCCESS);
}

