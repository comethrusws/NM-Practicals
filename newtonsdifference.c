//Newtons Forward and backward difference

#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to perform Newton's forward difference interpolation
double newtonForwardInterpolation(double x[], double y[], int n, double xi) {
    double result = 0.0;
    double h = x[1] - x[0];
    double u = (xi - x[0]) / h;

    double y_diff[n][n];
    for (int i = 0; i < n; i++) {
        y_diff[i][0] = y[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y_diff[j][i] = y_diff[j + 1][i - 1] - y_diff[j][i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        double term = y_diff[0][i] / factorial(i);
        for (int j = 0; j < i; j++) {
            term *= (u - j);
        }
        result += term;
    }

    return result;
}

// Function to perform Newton's backward difference interpolation
double newtonBackwardInterpolation(double x[], double y[], int n, double xi) {
    double result = 0.0;
    double h = x[1] - x[0];
    double u = (xi - x[n - 1]) / h;

    double y_diff[n][n];
    for (int i = 0; i < n; i++) {
        y_diff[i][0] = y[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y_diff[j][i] = y_diff[j][i - 1] - y_diff[j - 1][i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        double term = y_diff[n - 1][i] / factorial(i);
        for (int j = 0; j < i; j++) {
            term *= (u + j);
        }
        result += term;
    }

    return result;
}

int main() {
    // Example: Interpolate the points (0, 2), (1, 3), (3, 5), (4, 6)
    double x[] = {0, 1, 3, 4}; // x-coordinates of the points
    double y[] = {2, 3, 5, 6}; // y-coordinates of the points
    int n = sizeof(x) / sizeof(x[0]); // Number of points
    double xi = 2; // Point at which to interpolate

    // Interpolate the value at xi using Newton's forward difference interpolation
    double forwardInterpolatedValue = newtonForwardInterpolation(x, y, n, xi);
    printf("Forward Interpolated value at x = %.2lf is: %.2lf\n", xi, forwardInterpolatedValue);

    // Interpolate the value at xi using Newton's backward difference interpolation
    double backwardInterpolatedValue = newtonBackwardInterpolation(x, y, n, xi);
    printf("Backward Interpolated value at x = %.2lf is: %.2lf\n", xi, backwardInterpolatedValue);

    return 0;
}
