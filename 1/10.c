#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
   double a, b;

   scanf("%lf", &a);
   scanf("%lf", &b);

   printf("%.4lf", pow(a,b));

   return 0;
}
