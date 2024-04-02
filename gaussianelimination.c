//Gaussian Elimination

#include <stdio.h>
#include <stdlib.h>

#define N 3 // Size of the square matrix

// Function to perform Gaussian elimination
void gaussianElimination(double mat[N][N+1]) {
    // Applying Gauss Elimination
    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            double ratio = mat[j][i]/mat[i][i];
            for(int k=0; k<=N; k++) {
                mat[j][k] -= ratio * mat[i][k];
            }
        }
    }
    
    // Back Substitution
    double solution[N];
    for(int i=N-1; i>=0; i--) {
        solution[i] = mat[i][N];
        for(int j=i+1; j<N; j++) {
            solution[i] -= mat[i][j]*solution[j];
        }
        solution[i] /= mat[i][i];
    }

    // Printing the solution
    printf("Solution:\n");
    for(int i=0; i<N; i++) {
        printf("x%d = %.2f\n", i+1, solution[i]);
    }
}

int main() {
    double mat[N][N+1]; // Augmented matrix

    // Example input matrix (3x3 augmented matrix)
    printf("Enter the augmented matrix coefficients row-wise (each row followed by the constant term):\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<=N; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }

    // Perform Gaussian Elimination
    gaussianElimination(mat);

    return 0;
}
