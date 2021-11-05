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

void block
(size_t n, double A[n][n], double B[n][n], double C[n][n])
{
    int I, J, K;
    const int N_BLK = n / BLK_SIZE;
    for (I = 0; I < N_BLK; I++)
        for (K = 0; K < N_BLK; K++)
            for (J = 0; J < N_BLK; J++) {
                int i, j, k;
                double temp[BLK_SIZE], f;
                for (j = 0; j < BLK_SIZE; j++) {
                    for (k = 0; k < BLK_SIZE; k++)
                        temp[k] = B[k + K * BLK_SIZE][j + J * BLK_SIZE];

                    for (i = 0; i < BLK_SIZE; i++) {
                        f = 0.0;
                        for (k = 0; k < BLK_SIZE; k++)
                            f += A[i + I * BLK_SIZE][k + K * BLK_SIZE] * temp[k];
                        C[i + I * BLK_SIZE][j + J * BLK_SIZE] += f;
                    }
                }
            }
}

