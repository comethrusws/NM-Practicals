//runge-kutta method

#include <stdio.h>

// Function to define the differential equation dy/dx
double f(double x, double y) {
    return x + y; // Example ODE, you can replace it with your own function
}

// Function to implement fourth-order Runge-Kutta method
void rungeKutta(double x0, double y0, double h, double xn) {
    double x = x0;
    double y = y0;
    
    printf("x\t\t y\n");
    printf("%.6f\t %.6f\n", x, y);
    
    while (x < xn) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h/2, y + k1/2);
        double k3 = h * f(x + h/2, y + k2/2);
        double k4 = h * f(x + h, y + k3);
        
        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
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
    
    // Perform fourth-order Runge-Kutta method
    rungeKutta(x0, y0, h, xn);
    
    return 0;
}
