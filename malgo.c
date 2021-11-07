#include "malgo.h"

int BLK_SIZE = 375;

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
 *   M(I, J)  = submatrix, upper left element is M[I*BLK_SIZE][J*BLK_SIZE]
 *            = { M[i][j] | I*BLK_SIZE <= i < (I+1)*BLK_SIZE,
 *                          J*BLK_SIZE <= j < (J+1)*BLK_SIZE }
 *
 * block algorithm:
 *   C = {000...0}
 *   for (0 <= I < BLK_N)
 *       for (0 <= J < BLK_N)
 *           for (0 <= K < BLK_N)
 *               C(I, J) += A(I, K) X B(K, J)
 *
 **********************************************************************************/

void block
(int n, double A[n][n], double B[n][n], double C[n][n])
{
    register int I, J, K, i, j, k;
    register int blk_size = BLK_SIZE;
    register double f;
    double temp[blk_size];

    for (I = 0; I < n; I += blk_size)
        for (K = 0; K < n; K += blk_size)
            for (J = 0; J < n; J += blk_size) {

                // C(I, J) += A(I, K) X B(K, J)
                for (j = 0; j < blk_size; j++) {
                    for (k = 0; k < blk_size; k++)
                        temp[k] = B[k + K][j + J];
                    for (i = 0; i < blk_size; i++) {
                        f = 0.0;
                        for (k = 0; k < blk_size; k++)
                            f += A[i + I][k + K] * temp[k];
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

                    for (i = 0; i < blk_size; i++) {
                        f = 0.0;
                        for (k = 0; k < blk_size; k++)
                            f += tmpA[i][k] * temp[k];
                        C[i + I][j + J] += f;
                    }
                }
            }
        }
}
