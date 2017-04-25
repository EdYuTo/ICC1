#include <stdlib.h>
#include <stdio.h>

int main()
{
    int cont;
    float n, soma = 0, dividendo = 1;

    scanf("%f", &n);

    for(cont = 0; cont < n; cont++) {

        soma = soma + dividendo/(n-cont);
        dividendo = dividendo + 2;
    }

    printf("%.4f", soma);
    return 0;
}
