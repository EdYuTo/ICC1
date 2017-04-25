#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float c, soma = 0;

    scanf("%d", &n);

    for (c = 1; c <= n; c++){

        soma = soma + (c/(n-c+1));
    }

    printf("%.4f\n", soma);

    return 0;
}
