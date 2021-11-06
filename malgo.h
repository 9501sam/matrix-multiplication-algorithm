#include <stddef.h>

extern int BLK_SIZE;

void loop_ijk       (int n, double A[n][n], double B[n][n], double C[n][n]);
void loop_reorder   (int n, double A[n][n], double B[n][n], double C[n][n]);
void matrix_col     (int n, double A[n][n], double B[n][n], double C[n][n]);
void block          (int n, double A[n][n], double B[n][n], double C[n][n]);
void block_copy     (int n, double A[n][n], double B[n][n], double C[n][n]);

