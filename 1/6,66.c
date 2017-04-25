#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
  int n, a;
  scanf("%d", &n);
  double x[n];
  double y[n];
  double r;

  for(a = 0; a < n; a++) {
        scanf("%lf %lf", &x[a], &y[a]);
  if(a>0) {
            r = r + sqrt(pow((x[a]-x[a-1]),2) + pow((y[a]-y[a-1]),2));
  }}
  printf("%.4f", r);

  return 0;
}
