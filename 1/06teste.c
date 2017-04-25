#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c, d, e, q = 0;
    double *p = 0;

    scanf("%d", &a);

    do {
        scanf("%d", &b);
        scanf("%d", &c);
        scanf("%d", &d);
        scanf("%d", &e);
            p = realloc(p, sizeof(double) * (q + 1));
            p[q++] = sqrt((d - b)+(d - b));
            p[q++] = sqrt((e - c)+(e - c));
    } while (q < a);
    q = 0;

    do {
         printf("%f\n", p[q]);
         q++;

    } while (q < a);





    free(p);
    return 0;
}
