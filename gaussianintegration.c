//gaussian integration algorithm

#include <stdio.h>
#include <math.h>

#define N 3 // Number of points in the Gaussian quadrature

// Function to evaluate the integrand
double f(double x) {
    return sin(x); // Example integrand, you can replace it with your own function
}

// Function to perform numerical integration using Gaussian quadrature
double gaussianIntegration(double a, double b) {
    double x[N] = {-0.7745966692, 0, 0.7745966692}; // Nodes (roots of Legendre polynomial P3(x))
    double w[N] = {0.5555555556, 0.8888888889, 0.5555555556}; // Weights

    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        double xi = ((b - a) * x[i] + a + b) / 2; // Transforming nodes to the interval [a, b]
        sum += w[i] * f(xi);
    }

    return (b - a) / 2 * sum; // Final result
}

int main() {
    double a, b; // Lower and upper limits of integration

    // Input lower and upper limits of integration
    printf("Enter lower limit of integration: ");
    scanf("%lf", &a);
    printf("Enter upper limit of integration: ");
    scanf("%lf", &b);

    // Perform numerical integration using Gaussian quadrature
    double integral = gaussianIntegration(a, b);

    // Print the result
    printf("Integral value using Gaussian quadrature: %lf\n", integral);

    return 0;
}
