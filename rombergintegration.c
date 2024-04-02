//romberg integration

#include <stdio.h>
#include <math.h>

#define MAX_ITER 10 // Maximum number of iterations

// Function to evaluate the integrand
double f(double x) {
    return sin(x); // Example integrand, you can replace it with your own function
}

// Function to perform numerical integration using the trapezoidal rule
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = f(a) + f(b); // Sum of first and last terms
    
    // Summation of middle terms
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * f(x);
    }
    
    return (h / 2) * sum; // Final result
}

// Function to perform Romberg integration
double rombergIntegration(double a, double b, double epsilon) {
    double R[MAX_ITER][MAX_ITER] = {{0}}; // Romberg table
    double h = b - a; // Initial step size
    
    R[0][0] = (f(a) + f(b)) * h / 2; // First approximation using trapezoidal rule
    
    for (int i = 1; i < MAX_ITER; i++) {
        // Compute R[i][0] using trapezoidal rule with smaller step size
        double sum = 0;
        for (int j = 1; j <= pow(2, i - 1); j++) {
            sum += f(a + (2 * j - 1) * h / pow(2, i));
        }
        R[i][0] = 0.5 * R[i - 1][0] + (h / pow(2, i)) * sum;
        
        // Compute other elements in the row
        for (int k = 1; k <= i; k++) {
            R[i][k] = R[i][k - 1] + (R[i][k - 1] - R[i - 1][k - 1]) / (pow(4, k) - 1);
        }
        
        // Check for convergence
        if (fabs(R[i][i] - R[i - 1][i - 1]) < epsilon)
            return R[i][i];
        
        h /= 2; // Halve the step size
    }
    
    return R[MAX_ITER - 1][MAX_ITER - 1]; // Return the last computed value
}

int main() {
    double a, b; // Lower and upper limits of integration
    double epsilon; // Tolerance for convergence
    
    // Input lower and upper limits of integration
    printf("Enter lower limit of integration: ");
    scanf("%lf", &a);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &b);
    
    // Input tolerance for convergence
    printf("Enter tolerance for convergence: ");
    scanf("%lf", &epsilon);
    
    // Perform Romberg integration
    double integral = rombergIntegration(a, b, epsilon);
    
    // Print the result
    printf("Integral value using Romberg integration: %lf\n", integral);
    
    return 0;
}
