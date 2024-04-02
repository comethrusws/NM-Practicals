//Newton's Divided Difference

#include <stdio.h>

// Function to calculate divided difference table
void dividedDifference(double x[], double y[], int n, double dd[][n]) {
    // Initialize the divided difference table with y values
    for (int i = 0; i < n; i++) {
        dd[i][0] = y[i];
    }

    // Populate the divided difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            dd[i][j] = (dd[i + 1][j - 1] - dd[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

// Function to perform Newton's divided difference interpolation
double newtonInterpolation(double x[], double y[], int n, double xi) {
    double result = 0.0;
    double dd[n][n]; // Divided difference table

    // Calculate divided difference table
    dividedDifference(x, y, n, dd);

    // Initialize result with the first divided difference
    result = dd[0][0];

    // Perform interpolation
    for (int j = 1; j < n; j++) {
        double term = dd[0][j];
        for (int i = 0; i < j; i++) {
            term *= (xi - x[i]);
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

    // Interpolate the value at xi using Newton's divided difference interpolation
    double interpolatedValue = newtonInterpolation(x, y, n, xi);
    printf("Interpolated value at x = %.2lf is: %.2lf\n", xi, interpolatedValue);

    return 0;
}
