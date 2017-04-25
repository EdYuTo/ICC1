#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char letra;
    char *texto = NULL;
    int contador = 0;

    do {
        letra = fgetc(stdin);
        texto = (char*)realloc(texto, sizeof(char)*(contador+1));
        texto[contador++] = (letra+32);
    } while (letra != 10);
        texto[--contador] = '\0';

    for (contador = 0 ; contador < strlen(texto); contador++){
        printf("%c", texto[contador]);
    }

    free(texto);
    return 0;
}
