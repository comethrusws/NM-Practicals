//laplacian equation

#include <stdio.h>
#include <math.h>

#define N 10 // Number of grid points
#define MAX_ITER 1000 // Maximum number of iterations
#define TOLERANCE 1e-6 // Tolerance for convergence

// Function to initialize the boundary conditions
void initializeBoundaryConditions(double grid[N][N]) {
    // Set boundary conditions
    for (int i = 0; i < N; i++) {
        grid[0][i] = 100.0; // Top boundary
        grid[N - 1][i] = 0.0; // Bottom boundary
        grid[i][0] = 75.0; // Left boundary
        grid[i][N - 1] = 50.0; // Right boundary
    }
}

// Function to perform one iteration of the Jacobi method
void jacobiIteration(double grid[N][N], double newGrid[N][N]) {
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            newGrid[i][j] = (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1]) / 4.0;
        }
    }
}

// Function to check for convergence
int checkConvergence(double grid[N][N], double newGrid[N][N]) {
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (fabs(grid[i][j] - newGrid[i][j]) > TOLERANCE) {
                return 0; // Not converged
            }
        }
    }
    return 1; // Converged
}

// Function to solve Laplace's equation using the Jacobi method
void solveLaplace(double grid[N][N]) {
    double newGrid[N][N];
    int iter = 0;
    
    initializeBoundaryConditions(grid);
    
    do {
        jacobiIteration(grid, newGrid);
        
        // Copy new grid values back to the original grid
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }
        
        iter++;
    } while (iter < MAX_ITER && !checkConvergence(grid, newGrid));
}

// Function to print the grid values
void printGrid(double grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f\t", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double grid[N][N] = {0};
    
    solveLaplace(grid);
    
    printf("Grid values after solving Laplace's equation:\n");
    printGrid(grid);
    
    return 0;
}
