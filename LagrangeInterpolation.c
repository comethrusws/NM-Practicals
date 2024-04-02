#include <stdio.h>

// Function to calculate the value of the Lagrange polynomial at a given point
double lagrangeInterpolation(double x[], double y[], int n, double xi) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    // Example: Interpolate the points (1, 2), (2, 3), (3, 4)
    double x[] = {1, 2, 3}; // x-coordinates of the points
    double y[] = {2, 3, 4}; // y-coordinates of the points
    int n = sizeof(x) / sizeof(x[0]); // Number of points
    double xi = 2.5; // Point at which to interpolate

    // Interpolate the value at xi using Lagrange interpolation
    double interpolatedValue = lagrangeInterpolation(x, y, n, xi);
    printf("Interpolated value at x = %.2lf is: %.2lf\n", xi, interpolatedValue);

    return 0;
}
