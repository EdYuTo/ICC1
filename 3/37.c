#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
   int b = 0;
   double a = 0, c = 0, e = 0, d = 0;
   double *p = 0;

   scanf("%lf", &a);

   for (b = 0; b < a; b++) {
       scanf("%lf", &c);
        p = (double *)realloc(p, sizeof(double)*(b+1));
        p[b] = c;
   }

   for (b = 0; b < a; b++) {
        d = d + p[b];
   }
    for (b = 0; b < a; b++) {
        e = e + ((p[b] - (d/a))*(p[b] - (d/a)));
        }

   printf("%.4lf\n", d/a);
   printf("%.4lf\n", (sqrt(e)/sqrt(a)));

   free(p);
   return 0;
}
