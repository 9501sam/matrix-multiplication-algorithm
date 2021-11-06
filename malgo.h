#include <stddef.h>

#ifndef BLK_SIZE
#define BLK_SIZE 200
#endif

void loop_ijk       (size_t n, double A[n][n], double B[n][n], double C[n][n]);
void loop_reorder   (size_t n, double A[n][n], double B[n][n], double C[n][n]);
void matrix_col     (size_t n, double A[n][n], double B[n][n], double C[n][n]);
void block          (size_t n, double A[n][n], double B[n][n], double C[n][n]);
void block_copy     (size_t n, double A[n][n], double B[n][n], double C[n][n]);

