#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, contador = 0, I;
    int *sequencia = NULL;

    scanf("%d", &N);

    for (contador = 0; contador < N; contador++) {
        scanf("%d", &I);
        sequencia = (int *)realloc(sequencia, sizeof(int)*(contador+1));
        sequencia[contador] = I;
    }
    for (; contador > 0; ) {
        printf("%d\n", sequencia[--contador]);
    }

    return 0;
}
