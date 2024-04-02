//simpsons 1/3 rule

#include <stdio.h>
#include <math.h>

// Function to evaluate the integrand
double f(double x) {
    return sin(x); // Example integrand, you can replace it with your own function
}

// Function to perform numerical integration using Simpson's 1/3 rule
double simpsonsOneThird(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = f(a) + f(b); // Sum of first and last terms
    
    // Summation of even terms
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        sum += 4 * f(x);
    }
    
    // Summation of odd terms
    for (int i = 2; i < n - 1; i += 2) {
        double x = a + i * h;
        sum += 2 * f(x);
    }
    
    return (h / 3) * sum; // Final result
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
    printf("Enter number of intervals (must be even): ");
    scanf("%d", &n);
    
    if (n % 2 != 0) {
        printf("Number of intervals must be even.\n");
        return 1;
    }
    
    // Perform numerical integration using Simpson's 1/3 rule
    double integral = simpsonsOneThird(a, b, n);
    
    // Print the result
    printf("Integral value using Simpson's 1/3 rule: %lf\n", integral);
    
    return 0;
}
