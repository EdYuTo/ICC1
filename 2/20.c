#include <stdlib.h>
#include <stdio.h>

int main()
{   int n, j, m, i = 0, c;

    scanf("%d %d %d", &n, &j, &m);

    for(c = 0; c < n; ) {
            i++;
        if(i%m==j%m) {
    printf("%d\n", i);
    c++;
        }
    }


    return 0;
}
