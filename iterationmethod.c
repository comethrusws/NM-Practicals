#include<stdio.h>
#include<math.h>
#define EPS 0.0001

float f(float x){
    return x*x*x +4;
}

float findFloatat(float x){
    return 1/sqrt(1+x);
}

float differentiate(float x){
    return -1/2*(pow((1+x), -3/2));
}

int main(){
    int maxIteration, i;
    float a,b,x0;
    int x;
    printf("Enter maximum number of iterations:");
    scanf("%d", &maxIteration);
    
    do{
        printf("enter values of a and b (starting boundary):");
        scanf("%f%f", &a, &b);
        if(f(a)*f(b)<0){
            printf("invalid");
            continue;
        }
        else{

            printf("roots betn %d and %f\n", i, x);
            break;
        }
    }while(1);

    x0=(a+b)/2;
    if(fabs(differentiate(x0)),1){
        printf("function corrent");
    }
    else{
        printf("wrong value dinchas saley???");
        return 0;
    }

    for(i=0; i<=maxIteration; i++){
        x=findFloatat(x0);
        if(fabs(x-x0)<EPS){
            printf("itertion=%d root=%f\n", i,x);
            return 0;
        }
        printf("iteration=%d root=%f\n", i,x);
        x0=x;
    }
    printf("root=%f totsl iteration=%d",x, --i);
    return 0;

}