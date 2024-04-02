//heuns method

#include <stdio.h>

// Function to define the differential equation dy/dx
double f(double x, double y) {
    return x + y; // Example ODE, you can replace it with your own function
}

// Function to implement Heun's method
void heunsMethod(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;
    double slope1, slope2;
    
    printf("x\t\t y\n");
    printf("%.6f\t %.6f\n", x, y);
    
    while (x < xn) {
        slope1 = f(x, y);
        slope2 = f(x + h, y + h * slope1);
        y = y + (h / 2) * (slope1 + slope2);
        x = x + h;
        
        printf("%.6f\t %.6f\n", x, y);
    }
}

int main() {
    double x0, y0; // Initial values
    double xn, h; // Final value of x and step size
    
    // Input initial values
    printf("Enter initial value of x: ");
    scanf("%lf", &x0);
    printf("Enter initial value of y: ");
    scanf("%lf", &y0);
    
    // Input final value of x and step size
    printf("Enter final value of x: ");
    scanf("%lf", &xn);
    printf("Enter step size (h): ");
    scanf("%lf", &h);
    
    // Perform Heun's method
    heunsMethod(x0, y0, h, xn);
    
    return 0;
}
