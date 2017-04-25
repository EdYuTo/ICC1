#include <stdlib.h>
#include <stdio.h>

int main()
{
    long int a, r, n, s;

    scanf("%ld %ld %ld", &a, &r, &n);

        s = a + (n-1)*r;
            printf("%ld\n", s);
        s = (2*a + (n-1)*r)*n/2;
            printf("%ld", s);

    return 0;
}
