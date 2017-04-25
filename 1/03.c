#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (int argc, char *argv[]){

    float a;

    scanf("%f", &a);

    printf("%.0f\n", floor(a));
    printf("%.4f\n", a - floor(a));

    if ((a - floor(a)) >= 0.5) a++;

    printf("%.0f",floor(a));

    return 0;
}
