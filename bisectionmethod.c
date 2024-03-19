#include <stdio.h>
#include <math.h>

double func(double x) {
    
    return x * x * x - x - 4;
}

double bisection(double a, double b, int max_iterations) {
    if (func(a) * func(b) >= 0) {
        printf("Error: Function has same sign at endpoints.\n");
        return NAN;
    }

    double c;
    int iterations = 0;

    while (iterations < max_iterations) {
        c = (a + b) / 2;

        if (func(c) == 0)
            break;
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;

        iterations++;
    }

    if (iterations == max_iterations)
        printf("Maximum iterations reached.\n");

    return c;
}

int main() {
    double a, b;
    int max_iterations;

    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    double root = bisection(a, b, max_iterations);

    if (!isnan(root))
        printf("The root is approximately: %lf\n", root);

    return 0;
}