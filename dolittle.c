//Doolittle algorithm for LU decomposition

#include <stdio.h>

#define N 3 // Size of the square matrix

// Function to perform LU decomposition using Doolittle's method
void doolittleLU(double A[N][N], double L[N][N], double U[N][N]) {
    // Initializing L and U matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                L[i][j] = 1.0; // Diagonal elements of L are 1
            else
                L[i][j] = 0.0;
            U[i][j] = 0.0;
        }
    }

    // Performing Doolittle's method
    for (int j = 0; j < N; j++) {
        for (int i = j; i < N; i++) {
            // Upper triangular matrix (U)
            double sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - sum;

            // Lower triangular matrix (L)
            if (i > j) {
                sum = 0;
                for (int k = 0; k < j; k++) {
                    sum += L[j][k] * U[k][i];
                }
                L[j][i] = (A[j][i] - sum) / U[j][j];
            }
        }
    }
}

int main() {
    double A[N][N], L[N][N], U[N][N];

    // Example input matrix (3x3 square matrix)
    printf("Enter the elements of the %dx%d matrix A:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Perform LU decomposition using Doolittle's method
    doolittleLU(A, L, U);

    // Print L matrix
    printf("\nLower triangular matrix (L):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f\t", L[i][j]);
        }
        printf("\n");
    }

    // Print U matrix
    printf("\nUpper triangular matrix (U):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f\t", U[i][j]);
        }
        printf("\n");
    }

    return 0;
}
