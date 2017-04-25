#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
   char numero, *digitos = NULL;
   int contador = 0, s = 0;

   do {
        numero = fgetc(stdin);
        digitos = (char *)realloc(digitos, sizeof(char)*(contador+1));
        digitos[contador++] = numero;

   } while (numero != 10);
   digitos[--contador] = '\0';
//acabo de perceber que usei esse do/while para tudo//
   for (contador = 0; contador < strlen(digitos); contador++) {
    s = s + (digitos[contador] - '0');
   }

   printf("%d", s);

   free(digitos);
   return 0;
}
