#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6
#define MAX_ITER 1000

double f(double x) {
    // Define your function here
    return x * x - 4;
}

double secant(double x0, double x1) {
    double x2, f0, f1, f2;
    int iter = 0;

    do {
        f0 = f(x0);
        f1 = f(x1);
        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        f2 = f(x2);

        printf("Iteration %d: x = %.8f, f(x) = %.8f\n", iter, x2, f2);

        x0 = x1;
        x1 = x2;

        iter++;
    } while (fabs(f2) > EPSILON && iter < MAX_ITER);

    return x2;
}

int main() {
    double x0 = 1.0, x1 = 3.0; // Initial guesses
    double root;

    printf("Initial guesses: x0 = %.8f, x1 = %.8f\n", x0, x1);
    root = secant(x0, x1);
    printf("Root found at x = %.8f\n", root);

    return 0;
}
