#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    char c;
    char *palavra = NULL;
    int contador = 0, t = 0, u, v = 0;

    do {
        c = fgetc(stdin);
        palavra = (char *)realloc(palavra, sizeof(char)*(contador+1));
        palavra[contador++] = c;
    } while (c != 10);
    palavra[contador-1] = '\0';

    u = strlen(palavra);


    for (contador = 0; contador < strlen(palavra); contador++) {
            if (palavra[contador] == palavra[--u]) {t = 1;}
            else {v = 1;}
        }
    if (t == 1 && v == 0) {printf("SIM");}
    else {printf("NAO");}

    free(palavra);
    return 0;
}
