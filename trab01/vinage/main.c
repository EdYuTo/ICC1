#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int contador = 0, cont = 0, cont1 = 0;
    char c, *msg = NULL, *chave = NULL;


    do {c = fgetc(stdin);
        msg = (char *)realloc(msg, sizeof(char)*(contador+1));
        msg[contador++] = c;
    } while (c != 10);
    contador--; //para poder utilizá-lo abaixo como referência

    do {c = fgetc(stdin);
        chave = (char*)realloc(chave, sizeof(char)*(cont+1));
        chave[cont++] = c;
    } while (c != 10);
        chave[cont-1] = '\0';

    for (cont = 0; cont < contador; cont++){
            if (cont1 < strlen(chave)) {
        if ((64 < msg[cont] && msg[cont] < (156 - chave[cont1]))){
            msg[cont] = msg[cont] + chave[cont1] - 65;
            cont1++;                               //criptografando..
        } else if (((msg[cont] + chave[cont1]) > 155) &&  (msg[cont] < 91)){
                msg[cont] = msg[cont] + chave[cont1]-91;
                cont1++;
            }}
            else {cont1 = 0;
            cont--;
            }
    }

    for (cont = 0; cont < contador; cont++) {
        printf("%c", msg[cont]);
    }

    free(msg);
    free(chave);
    return 0;
}
