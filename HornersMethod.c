//Horner's Method

#include <stdio.h>

// Function to evaluate a polynomial using Horner's method
double horner(double coefficients[], int degree, double x) {
    double result = coefficients[degree];
    for (int i = degree - 1; i >= 0; i--) {
        result = result * x + coefficients[i];
    }
    return result;
}

int main() {
    // Example: Evaluate the polynomial 2x^3 + 3x^2 - 6x + 4 at x = 2
    double coefficients[] = {2, 3, -6, 4};
    int degree = 3; // Degree of the polynomial
    double x = 2;   // Value at which to evaluate the polynomial

    // Evaluate the polynomial using Horner's method
    double result = horner(coefficients, degree, x);
    printf("The value of the polynomial at x = %.2lf is: %.2lf\n", x, result);

    return 0;
}
