#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, cont;
    float soma = 0, a = 0;

    scanf("%d", &n);

    for (cont = 1; cont <= n; cont++){
    a++;
            if ((cont/2)*2 != cont){
                soma = soma + (1/a);
            }

            else if ((cont/2)*2 == cont){
                soma = soma - (1/a);
            }
    }

    printf("%.4f", soma);
    return 0;
}
