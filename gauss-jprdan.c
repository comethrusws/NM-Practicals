//Gauss-Jordan method

#include <stdio.h>
#include <stdlib.h>

#define N 3 // Size of the square matrix

// Function to swap two rows of a matrix
void swapRows(double mat[N][N+1], int row1, int row2) {
    for (int i = 0; i <= N; i++) {
        double temp = mat[row1][i];
        mat[row1][i] = mat[row2][i];
        mat[row2][i] = temp;
    }
}

// Function to perform Gauss-Jordan elimination
void gaussJordan(double mat[N][N+1]) {
    for (int i = 0; i < N; i++) {
        // Pivot element
        double pivot = mat[i][i];

        // Make pivot element 1
        for (int j = i + 1; j <= N; j++)
            mat[i][j] /= pivot;
        mat[i][i] = 1.0;

        // Make other elements in the column zero
        for (int j = 0; j < N; j++) {
            if (j != i) {
                double factor = mat[j][i];
                for (int k = i; k <= N; k++)
                    mat[j][k] -= factor * mat[i][k];
            }
        }
    }
}

int main() {
    double mat[N][N+1]; // Augmented matrix

    // Example input matrix (3x3 augmented matrix)
    printf("Enter the augmented matrix coefficients row-wise (each row followed by the constant term):\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }

    // Perform Gauss-Jordan elimination
    gaussJordan(mat);

    // Printing the solution
    printf("Solution:\n");
    for(int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i+1, mat[i][N]);
    }

    return 0;
}
