#include <stdlib.h>
#include <stdio.h>

int main()
{
    long int n, m = 0, cont, *impar = NULL, c, d = 0;

    scanf("%ld", &n);

    for(cont = 1; cont <= n; cont++) {
        m = m + cont;                      //Para saber quantos ímpares serão gerados...
    }

    for(cont = 1; cont < m; cont++) {
        impar = (long int*)realloc(impar, sizeof(long int)*(cont+1));
        impar[0] = 1;
        impar[cont] = impar[cont-1] + 2;
    }

   for(c = 1, cont = 0; c <= n; c++){
        d = d + c;
    for( ; cont < d && cont < m; cont++){
        printf("%ld ", impar[cont]);
    }

    printf("\n");
   }

    free(impar);
    return 0;
}
