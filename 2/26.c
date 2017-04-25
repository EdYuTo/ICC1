#include <stdlib.h>
#include <stdio.h>

//N trabalhos, N decimais ===> notas

int main()
{
    int n, cont;
    float *nota = NULL, soma = 0;

    scanf("%d", &n);

    for (cont = 0; cont < n; cont++) {
        nota = (float*)realloc(nota, sizeof(float)*(cont+1));
        scanf("%f", &nota[cont]);
        soma = soma + 1/(nota[cont]+1);
    }

    soma = (n/soma) - 1;

    printf("%.2f", soma);

    free(nota);
    return 0;
}
