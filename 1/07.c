#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b,c;

    scanf("%f", &a);

    b = floor(a / 4);
    c = a - (4*b);

    if(c==0) {
            printf("SIM");
            }

    else {
        printf("NAO");
        }

    return 0;
}
