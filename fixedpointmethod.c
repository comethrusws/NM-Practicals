//Fixed point method

#include <stdio.h>
#include <math.h>

// Define the function for which we want to find the root
double f(double x) {
    // Example function: x^3 - x - 1
    return pow(x, 3) - x - 1;
}

// Implement the fixed-point method
double fixedPoint(double initial_guess, double tolerance, int max_iterations) {
    double x0 = initial_guess;
    double x1;
    int iterations = 0;
    
    do {
        // Compute the next approximation using the fixed-point iteration formula
        x1 = f(x0) + x0;

        // Check for convergence
        if (fabs(x1 - x0) < tolerance) {
            printf("Converged to solution after %d iterations.\n", iterations);
            return x1;
        }

        x0 = x1;
        iterations++;
    } while (iterations < max_iterations);

    printf("Did not converge within the specified maximum number of iterations.\n");
    return x1;
}

int main() {
    double initial_guess = 1.0; // Initial guess
    double tolerance = 0.0001;  // Tolerance for convergence
    int max_iterations = 100;   // Maximum number of iterations
    
    // Find the root using fixed-point method
    double root = fixedPoint(initial_guess, tolerance, max_iterations);
    printf("Approximate root: %lf\n", root);

    return 0;
}
