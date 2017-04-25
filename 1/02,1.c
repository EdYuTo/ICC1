#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;

    printf("Insira dois inteiros: \n");

    scanf("%d", &a);
    scanf("%d", &b);

    printf("AND %d\n", a & b);
    printf("OR %d\n", a | b);
    printf("Exclusive OR %d\n", a ^ b);
    printf("Complement a %d\n", ~a);
    printf("Complement b %d\n", ~b);
    printf("a>>2 %d\n", a >> 2);
    printf("b<<2 %d\n", b << 2);

    return 0;
}

