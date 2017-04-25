#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int c, d;
    double milhar = 10, dezena = 0, raiz;
    double *especial = NULL;

   for(c = 0; milhar <= 99; milhar++, dezena = 0){
    while (dezena <= 99) {
      raiz = (100*milhar) + dezena;
        if (sqrt(raiz) == (milhar+dezena)){
            especial = realloc(especial, sizeof(double)*(c+1));
            especial[c++] = (100*milhar + dezena);
                } dezena++;
   }
   }

   for (d = 0; d < c; d++) {
        printf("%.lf\n", especial[d]);
   }

    free(especial);
    return 0;
}
