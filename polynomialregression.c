//Polynomial regression

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DEGREE 10 // Maximum degree of the polynomial

// Function to compute the sum of squares of residuals
double computeSSR(double x[], double y[], double coefficients[], int n, int degree) {
    double ssr = 0.0;
    for (int i = 0; i < n; i++) {
        double predicted = 0.0;
        for (int j = 0; j <= degree; j++) {
            predicted += coefficients[j] * pow(x[i], j);
        }
        ssr += pow(y[i] - predicted, 2);
    }
    return ssr;
}

// Function to perform polynomial regression
void polynomialRegression(double x[], double y[], int n, int degree, double coefficients[]) {
    // Create matrices A and B for the linear system
    double A[MAX_DEGREE + 1][MAX_DEGREE + 1];
    double B[MAX_DEGREE + 1];
    
    // Initialize matrices A and B
    for (int i = 0; i <= degree; i++) {
        B[i] = 0.0;
        for (int j = 0; j <= degree; j++) {
            A[i][j] = 0.0;
            for (int k = 0; k < n; k++) {
                A[i][j] += pow(x[k], i + j);
            }
        }
        for (int k = 0; k < n; k++) {
            B[i] += pow(x[k], i) * y[k];
        }
    }
    
    // Solve the linear system using Gaussian elimination
    for (int i = 0; i <= degree; i++) {
        for (int j = i + 1; j <= degree; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = 0; k <= degree; k++) {
                A[j][k] -= factor * A[i][k];
            }
            B[j] -= factor * B[i];
        }
    }
    
    // Back substitution
    for (int i = degree; i >= 0; i--) {
        coefficients[i] = B[i];
        for (int j = i + 1; j <= degree; j++) {
            coefficients[i] -= A[i][j] * coefficients[j];
        }
        coefficients[i] /= A[i][i];
    }
}

int main() {
    // Example data
    double x[] = {1, 2, 3, 4, 5}; // Independent variable
    double y[] = {2, 3, 5, 7, 11}; // Dependent variable
    int n = sizeof(x) / sizeof(x[0]); // Number of data points
    int degree = 2; // Degree of the polynomial
    
    // Coefficients to be estimated
    double coefficients[MAX_DEGREE + 1];
    
    // Perform polynomial regression
    polynomialRegression(x, y, n, degree, coefficients);
    
    // Compute the sum of squares of residuals
    double ssr = computeSSR(x, y, coefficients, n, degree);
    
    // Print the estimated coefficients
    printf("Estimated coefficients:\n");
    for (int i = 0; i <= degree; i++) {
        printf("coefficients[%d] = %.4f\n", i, coefficients[i]);
    }
    
    // Print the sum of squares of residuals
    printf("Sum of squares of residuals: %.4f\n", ssr);
    
    return 0;
}
