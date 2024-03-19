#include <stdio.h>
#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

double calculate_slope(Point points[], int n) {
    double sum_xy = 0, sum_x = 0, sum_y = 0, sum_x_squared = 0;

    for (int i = 0; i < n; i++) {
        sum_xy += points[i].x * points[i].y;
        sum_x += points[i].x;
        sum_y += points[i].y;
        sum_x_squared += points[i].x * points[i].x;
    }

    double numerator = (n * sum_xy) - (sum_x * sum_y);
    double denominator = (n * sum_x_squared) - (sum_x * sum_x);

    return numerator / denominator;
}

// y-intercept (b) of the line
double calculate_intercept(Point points[], int n, double slope) {
    double sum_x = 0, sum_y = 0;

    for (int i = 0; i < n; i++) {
        sum_x += points[i].x;
        sum_y += points[i].y;
    }

    return (sum_y - (slope * sum_x)) / n;
}

int main() {
    int n;
    Point points[MAX_POINTS];

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the points as (x, y) pairs:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d: ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    // slope and y-intercept
    double slope = calculate_slope(points, n);
    double intercept = calculate_intercept(points, n, slope);

    printf("Equation of the line: y = %.2fx + %.2f\n", slope, intercept);

    return 0;
}
