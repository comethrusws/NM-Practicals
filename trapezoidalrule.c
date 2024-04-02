//trapezoidal rule

#include <stdio.h>
#include <math.h>

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

int main() {
    double a, b; // Lower and upper limits of integration
    int n; // Number of intervals
    
    // Input lower and upper limits of integration
    printf("Enter lower limit of integration: ");
    scanf("%lf", &a);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &b);
    
    // Input number of intervals
    printf("Enter number of intervals: ");
    scanf("%d", &n);
    
    // Perform numerical integration using the trapezoidal rule
    double integral = trapezoidalRule(a, b, n);
    
    // Print the result
    printf("Integral value using trapezoidal rule: %lf\n", integral);
    
    return 0;
}
