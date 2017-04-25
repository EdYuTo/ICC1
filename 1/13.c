#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b = 0, c = 0;
    int *impares = NULL;

    scanf("%d", &a);

    for (b = 0; b < a; b++) {
        impares = (int *)realloc(impares, sizeof(int)*(b+1));
        c = c + 2;
        impares[b] = c;
    }

    for (b = 0; b < a; b++) {
        printf("%d\n", (impares[b]-1));
    }


    free(impares);
    return 0;
}
