#include "malgo.h"

int BLK_SIZE = 300;

void loop_ijk
(int n, double A[n][n], double B[n][n], double C[n][n])
{
    register int i, j, k;
    register double f;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            f = 0.0;
            for (k = 0; k < n; k++)
                f += A[i][k] * B[k][j];
            C[i][j] = f;
        }
}

void loop_reorder
(int n, double A[n][n], double B[n][n], double C[n][n])
{
    register int i, j, k;
    register double f;
    for (i = 0; i < n; i++)
        for (k = 0; k < n; k++) {
            f = A[i][k];
            for (j = 0; j < n; j++)
                C[i][j] += f * B[k][j];
        }
}

void matrix_col
(int n, double A[n][n], double B[n][n], double C[n][n])
{
    register int i, j, k;
    register double f;
    double temp[n];
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

/***********************************************************************************
 * let
 *   n        = size of original matrix,
 *   BLK_SIZE = size of submatrix,
 *   BLK_N    = n / BLK_SIZE,
 *   M(I, J)  = submatrix, upper left element is M[I][J]
 *            = { M[i][j] | I*BLK_SIZE <= i < I+BLK_SIZE,
 *                          J*BLK_SIZE <= j < J+BLK_SIZE }
 *
 * block algorithm:
 *   C = {000...0}
 *   for (0 <= I < BLK_SIZE)
 *       for (0 <= J < BLK_SIZE)
 *           for (0 <= K < BLK_SIZE)
 *               C(I, J) += A(I, K) X B(K, J)
 *
 **********************************************************************************/

void block
(int n, double A[n][n], double B[n][n], double C[n][n])
{
    register int I, J, K, i, j, k;
    register int blk_size = BLK_SIZE;
    register double f;
    register double *ptr_A, *ptr_B;
    double temp[blk_size];

    for (I = 0; I < n; I += blk_size)
        for (K = 0; K < n; K += blk_size)
            for (J = 0; J < n; J += blk_size) {

                // C(I, J) += A(I, K) X B(K, J)
                for (j = 0; j < blk_size; j++) {
                    ptr_B = &B[K][j + J];
                    for (k = 0; k < blk_size; k++) {
                        temp[k] = *ptr_B;
                        ptr_B += n;
                    }

                    for (i = 0; i < blk_size; i++) {
                        f = 0.0;

                        ptr_A = &A[i + I][K];
                        for (k = 0; k < blk_size; k++)
                            f += *(ptr_A++) * temp[k];
                        C[i + I][j + J] += f;
                    }
                }
            }
}

void block_copy
(int n, double A[n][n], double B[n][n], double C[n][n])
{
    register int I, J, K, i, j, k;
    register int blk_size = BLK_SIZE;
    register double f;
    register double *ptr_A;
    double temp[blk_size];
    double tmpA[blk_size][blk_size], tmpB[blk_size][blk_size];

    for (I = 0; I < n; I += blk_size)
        for (K = 0; K < n; K += blk_size) {

            // copy block A(I, K) into tmpA
            for (i = 0; i < blk_size; i++)
                for (k = 0; k < blk_size; k++)
                    tmpA[i][k] = A[i + I][k + K];

            for (J = 0; J < n; J += blk_size) {
                // copy block B(K, J) into tmpB
                for (k = 0; k < blk_size; k++)
                    for (j = 0; j < blk_size; j++)
                        tmpB[k][j] = B[k + K][j + J];

                // C(I, J) += A(I, K) X B(K, J)
                for (j = 0; j < blk_size; j++) {
                    for (k = 0; k < blk_size; k++)
                        temp[k] = tmpB[k][j];

                    ptr_A = &tmpA[0][0];
                    for (i = 0; i < blk_size; i++) {
                        f = 0.0;
                        for (k = 0; k < blk_size; k++)
                            f += *(ptr_A++) * temp[k];
                        C[i + I][j + J] += f;
                    }
                }
            }
        }
}
