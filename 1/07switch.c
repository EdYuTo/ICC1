#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b;
    int c;

    scanf("%d", &a);

    b = floor(a / 4);
    c = a - (4*b);

    if (c > 0) c = 1;

    switch(c){
        case '0':
            printf("SIM");
            break;

        case '1' :
        printf("NAO");
        break;
    }

    return 0;
}
