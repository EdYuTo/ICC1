#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, i, j, c, d = 0;
    int *multiplos = NULL;

    scanf("%d %d %d", &n, &i, &j);

   for (c = 0; c < n; d++) {
        if ((((d/i)*i)==d) || (((d/j)*j)==d)) {
            multiplos = (int *)realloc(multiplos, sizeof(int)*(c+1));
            multiplos[c++] = d;
        }
    }
    for (c = 0; c < n; c++) {
        printf("%d\n", multiplos[c]);
 }

    free(multiplos);
    return 0;
}
