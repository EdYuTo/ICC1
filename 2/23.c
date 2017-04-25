#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{ double a, q, n, pg;

    scanf("%lf %lf %lf", &a, &q, &n);

    pg = a*pow(q, n-1);

    printf("%.2lf\n", pg);

    pg = a*(pow(q,n)-1)/(q-1);

    printf("%.2lf", pg);
    return 0;
}
