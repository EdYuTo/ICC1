#include <stdlib.h>
#include <stdio.h>

int main()
{
   int b, c;
   double x, r;
   double *saida = NULL;

    scanf("%lf %lf %d", &x, &r, &b);

    for (c = 1; c <= b; c++) {
        saida = (double*)realloc(saida, sizeof(double)*(c +1));
        saida[0] = x;
        saida[c] = (r*saida[c-1]*(1-saida[c-1]));
    }

    for (c = 1; c <= b; c++) {
        printf("%d %lf\n",c ,saida[c]);
    }

    free(saida);
    return 0;
}
