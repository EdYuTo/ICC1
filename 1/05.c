#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

int main(int argc, char *argv[])
{
    double a, b, c, d, r1, r2;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    d = (b*b) - (4*a*c);

    r1 = (-b + sqrt(d)) / 2*a;
    r2 = (-b - sqrt(d)) / 2*a;

    if(d>=0 && r1 != r2) {
            printf("REAIS\n");
            printf("R1 %lf\n", r1);
            printf("R2 %lf\n", r2);
    }
else;

    if(d>=0 && r1 == r2) {
            printf("DUPLA\n");
            printf("RD %lf", r1);
    }
    else;


    if (d < 0) {
    d = -d;
    r1 = ((-b) / (2*a));
    r2 = (sqrt(d)/ (2*a));
        printf("COMPLEXAS\n");
        printf("R %lf\n",r1);
        printf("I %lf\n",r2);
    }

    return 0;

}
