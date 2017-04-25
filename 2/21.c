#include <stdlib.h>
#include <stdio.h>

int main()
{
    int f, g;
    double a[4], b;

    for (f = 0; f < 4; f++){
            scanf("%lf", &b);
            a[f] = b;
    }
for(g=0;g<4;g++){
   	for (f = 0; f < 3; f++) {
			if (a[f] > a[f+1]) {
				b = a[f+1];
				a[f+1] = a[f];
				a[f] = b;
			}}}

    printf("%.4lf\n", ((a[1]+a[2]+a[3])/3));
    return 0;
}
