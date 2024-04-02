//simpsons 3/8 rule

#include <stdio.h>
#include <math.h>

// Function to evaluate the integrand
double f(double x) {
    return sin(x); // Example integrand, you can replace it with your own function
}

// Function to perform numerical integration using Simpson's 3/8 rule
double simpsonsThreeEighth(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = f(a) + f(b); // Sum of first and last terms
    
    // Summation of terms
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) // If i is a multiple of 3
            sum += 2 * f(x);
        else
            sum += 3 * f(x);
    }
    
    return (3 * h / 8) * sum; // Final result
}

int main() {
    double a, b; // Lower and upper limits of integration
    int n; // Number of intervals
    
    // Input lower and upper limits of integration
    printf("Enter lower limit of integration: ");
    scanf("%lf", &a);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &b);
    
    // Input number of intervals (must be multiple of 3)
    printf("Enter number of intervals (must be multiple of 3): ");
    scanf("%d", &n);
    
    if (n % 3 != 0) {
        printf("Number of intervals must be multiple of 3.\n");
        return 1;
    }
    
    // Perform numerical integration using Simpson's 3/8 rule
    double integral = simpsonsThreeEighth(a, b, n);
    
    // Print the result
    printf("Integral value using Simpson's 3/8 rule: %lf\n", integral);
    
    return 0;
}
