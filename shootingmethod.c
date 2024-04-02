//shooting method

#include <stdio.h>
#include <math.h>

// Function to define the differential equation y'' = f(x, y, y')
double f(double x, double y, double y_prime) {
    return 2 * x - y_prime; // Example ODE, you can replace it with your own function
}

// Function to implement the Runge-Kutta method to solve the initial value problem
void rungeKutta(double x0, double y0, double yp0, double h, double xn, double *y_out) {
    double x = x0;
    double y = y0;
    double yp = yp0;
    
    while (x < xn) {
        double k1y = h * yp;
        double k1yp = h * f(x, y, yp);
        
        double k2y = h * (yp + k1yp / 2);
        double k2yp = h * f(x + h / 2, y + k1y / 2, yp + k1yp / 2);
        
        double k3y = h * (yp + k2yp / 2);
        double k3yp = h * f(x + h / 2, y + k2y / 2, yp + k2yp / 2);
        
        double k4y = h * (yp + k3yp);
        double k4yp = h * f(x + h, y + k3y, yp + k3yp);
        
        y = y + (k1y + 2 * k2y + 2 * k3y + k4y) / 6;
        yp = yp + (k1yp + 2 * k2yp + 2 * k3yp + k4yp) / 6;
        x = x + h;
    }
    
    *y_out = y;
}

// Function to implement the shooting method
double shootingMethod(double x0, double y0, double xn, double y_target, double tolerance) {
    double yp_lower = 0; // Initial guess for the lower bound of y'
    double yp_upper = 1; // Initial guess for the upper bound of y'
    double y_lower, y_upper;
    double y_guess;
    
    while (1) {
        rungeKutta(x0, y0, yp_lower, 0.001, xn, &y_lower);
        rungeKutta(x0, y0, yp_upper, 0.001, xn, &y_upper);
        
        y_guess = y_upper - (y_upper - y_lower) * (y_target - y_upper) / (y_lower - y_upper);
        
        rungeKutta(x0, y0, y_guess, 0.001, xn, &y_guess);
        
        if (fabs(y_guess - y_target) < tolerance) {
            break;
        } else if (y_guess > y_target) {
            yp_upper = y_guess;
        } else {
            yp_lower = y_guess;
        }
    }
    
    return y_guess;
}

int main() {
    double x0, y0; // Initial values
    double xn; // Final value of x
    double y_target; // Target value of y at xn
    double tolerance; // Tolerance for convergence
    
    // Input initial values
    printf("Enter initial value of x: ");
    scanf("%lf", &x0);
    printf("Enter initial value of y: ");
    scanf("%lf", &y0);
    
    // Input final value of x and target value of y
    printf("Enter final value of x: ");
    scanf("%lf", &xn);
    printf("Enter target value of y at x = %.2f: ", xn);
    scanf("%lf", &y_target);
    
    // Input tolerance for convergence
    printf("Enter tolerance for convergence: ");
    scanf("%lf", &tolerance);
    
    // Solve the boundary value problem using the shooting method
    double yp_final = shootingMethod(x0, y0, xn, y_target, tolerance);
    
    printf("The value of y' at x = %.2f is: %.6f\n", xn, yp_final);
    
    return 0;
}
