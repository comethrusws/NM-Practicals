//Non-linear regression with exponential model

#include <stdio.h>
#include <math.h>

#define MAX_ITER 1000
#define TOLERANCE 0.0001

// Exponential model function
double exponentialModel(double a, double b, double x) {
    return a * exp(b * x);
}

// Compute the sum of squares of residuals
double computeSSR(double a, double b, double x[], double y[], int n) {
    double ssr = 0.0;
    for (int i = 0; i < n; i++) {
        double predicted = exponentialModel(a, b, x[i]);
        ssr += pow(y[i] - predicted, 2);
    }
    return ssr;
}

// Perform non-linear regression using the exponential model
void nonLinearRegression(double x[], double y[], int n, double *a, double *b) {
    // Initial guesses for parameters a and b
    *a = 1.0;
    *b = 1.0;

    double delta_a, delta_b;
    double prev_ssr, ssr = 0.0;
    int iter = 0;

    // Iterative optimization
    do {
        prev_ssr = ssr;
        ssr = computeSSR(*a, *b, x, y, n);

        // Partial derivatives of SSR with respect to a and b
        double d_ssr_da = 0.0, d_ssr_db = 0.0;
        for (int i = 0; i < n; i++) {
            double predicted = exponentialModel(*a, *b, x[i]);
            d_ssr_da += -2 * (y[i] - predicted) * exp(*b * x[i]);
            d_ssr_db += -2 * (y[i] - predicted) * (*a) * x[i] * exp(*b * x[i]);
        }

        // Update parameters using gradient descent
        delta_a = -0.01 * d_ssr_da; // learning rate = 0.01
        delta_b = -0.01 * d_ssr_db;
        *a += delta_a;
        *b += delta_b;

        iter++;
    } while (fabs(prev_ssr - ssr) > TOLERANCE && iter < MAX_ITER);

    printf("Converged after %d iterations.\n", iter);
}

int main() {
    // Example data
    double x[] = {1, 2, 3, 4, 5}; // Independent variable
    double y[] = {3, 8, 20, 45, 85}; // Dependent variable
    int n = sizeof(x) / sizeof(x[0]); // Number of data points

    // Parameters to be estimated
    double a, b;

    // Perform non-linear regression
    nonLinearRegression(x, y, n, &a, &b);

    // Print the estimated parameters
    printf("Estimated parameters:\n");
    printf("a = %.4f\n", a);
    printf("b = %.4f\n", b);

    return 0;
}
