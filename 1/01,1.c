#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Tamanho, em bytes, de cada um dos tipos de dados da linguagem C: \n");
    printf("char: %d\n", sizeof(char));
    printf("unsigned int: %d\n", sizeof(unsigned int));
    printf("short int: %d\n", sizeof(short int));
    printf("int: %d\n", sizeof(int));
    printf("long int: %d\n", sizeof(long int));
    printf("unsigned long int: %d\n", sizeof(unsigned long int));
    printf("long long int: %d\n", sizeof(long long int));
    printf("float: %d\n", sizeof(float));
    printf("double: %d\n", sizeof(double));
    printf("long double: %d\n", sizeof(long double));

    return 0;
}
