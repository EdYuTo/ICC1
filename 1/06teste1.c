#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, q = 0;
    double b, c, d, e;
    double *p = 0;

    scanf("%d", &a);

    do {
        scanf("%f", &b);
        scanf("%f", &c);
        scanf("%f", &d);
        scanf("%f", &e);
            p = realloc(p, sizeof(double) * (q + 1));
            p[q++] = sqrt(pow((d-b) ,2) + pow((e-c), 2));

    } while (q < ceil(a/2));
    q = 0;

    do {
         printf("%.4f\n", p[q++]);

    } while (q < a);

    free(p);
    return 0;
}
