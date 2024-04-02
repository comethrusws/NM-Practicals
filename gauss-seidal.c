//gauss-seidal method

#include <stdio.h>
#include <math.h>

#define N 3 // Number of equations (size of the system)
#define MAX_ITER 100 // Maximum number of iterations
#define TOLERANCE 0.0001 // Tolerance for convergence

// Function to perform Gauss-Seidel method
void gaussSeidel(double A[N][N], double b[N], double x[N]) {
    double x_new[N]; // Temporary array to store updated values of x
    
    for (int iter = 0; iter < MAX_ITER; iter++) {
        for (int i = 0; i < N; i++) {
            double sum1 = 0.0, sum2 = 0.0;
            for (int j = 0; j < i; j++) {
                sum1 += A[i][j] * x_new[j];
            }
            for (int j = i + 1; j < N; j++) {
                sum2 += A[i][j] * x[j];
            }
            x_new[i] = (b[i] - sum1 - sum2) / A[i][i];
        }
        
        // Checking for convergence
        int converged = 1;
        for (int i = 0; i < N; i++) {
            if (fabs(x_new[i] - x[i]) > TOLERANCE) {
                converged = 0;
                break;
            }
        }
        
        // Update x values
        for (int i = 0; i < N; i++) {
            x[i] = x_new[i];
        }
        
        if (converged) {
            printf("Converged after %d iterations.\n", iter + 1);
            return;
        }
    }
    
    printf("Did not converge within %d iterations.\n", MAX_ITER);
}

int main() {
    double A[N][N]; // Coefficient matrix
    double b[N]; // Right-hand side vector
    double x[N] = {0}; // Initial guess for solution vector x
    
    // Example input matrix A
    printf("Enter the coefficient matrix A (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    
    // Example input vector b
    printf("Enter the right-hand side vector b (%d elements):\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &b[i]);
    }
    
    // Perform Gauss-Seidel method
    gaussSeidel(A, b, x);
    
    // Print the solution vector x
    printf("Solution vector x:\n");
    for (int i = 0; i < N; i++) {
        printf("%.6f\n", x[i]);
    }
    
    return 0;
}
