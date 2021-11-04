#include "malgo.h"

void loop_ijk
(size_t n, double A[n][n], double B[n][n], double C[n][n])
{
    double f;
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            f = 0.0;
            for (k = 0; k < n; k++)
                f += A[i][k] * B[k][j];
            C[i][j] = f;
        }
}

void loop_reorder
(size_t n, double A[n][n], double B[n][n], double C[n][n])
{
    double f;
    int i, j, k;
    for (i = 0; i < n; i++)
        for (k = 0; k < n; k++) {
            f = A[i][k];
            for (j = 0; j < n; j++)
                C[i][j] += f * B[k][j];
        }
}

void matrix_col
(size_t n, double A[n][n], double B[n][n], double C[n][n])
{
    int i, j, k;
    double temp[n], f;
    for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) // copy to temp
            temp[k] = B[k][j];

        for (i = 0; i < n; i++) {
            f = 0.0;
            for (k = 0; k < n; k++)
                f += A[i][k] * temp[k];
            C[i][j] = f;
        }
    }
}
