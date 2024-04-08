#include<stdio.h>
#include<math.h>
#define EPS 0.0001

float f(float x){
    return x*x*x + 4;
}

float findRootAt(float x){
    return 1/sqrt(1+x);
}

float differentiate(float x){
    return -1/2*(pow((1+x), -3/2));
}

int main(){
    int maxIteration, i;
    float a, b, x0;
    float x;
    
    printf("Enter maximum number of iterations:");
    scanf("%d", &maxIteration);
    
    do {
        printf("Enter values of a and b (starting boundary):");
        scanf("%f%f", &a, &b);
        if (f(a) * f(b) < 0) {
            break;
        }
        else {
            printf("Invalid starting boundary.\n");
            continue;
        }
    } while (1);

    x0 = (a + b) / 2;
    if (fabs(differentiate(x0)) < 1) {
        printf("Function is correct.\n");
    }
    else {
        printf("Function is incorrect.\n");
        return 0;
    }

    for (i = 0; i <= maxIteration; i++) {
        x = findRootAt(x0);
        if (fabs(x - x0) < EPS) {
            printf("Iteration = %d, Root = %f\n", i, x);
            return 0;
        }
        printf("Iteration = %d, Root = %f\n", i, x);
        x0 = x;
    }
    printf("Root = %f, Total Iterations = %d\n", x, --i);
    return 0;
}
