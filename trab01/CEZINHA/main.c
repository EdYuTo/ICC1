//EDSON YUDI TOMA - 9791305//

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int k, contador = 0, cont;
    char c, *msg = NULL;

    scanf("%d", &k);

    do {c = fgetc(stdin);} while (c != 10); //para saltar o ENTER da entrada (constante ENTER texto)

    do {c = fgetc(stdin);
        msg = (char *)realloc(msg, sizeof(char)*(contador+1));
        msg[contador++] = c;
    } while (c != 10);
    contador--; //para poder utilizá-lo abaixo como referência

    for (cont = 0; cont < contador; cont++){
        if ((64 < msg[cont] && msg[cont] < (91 - k))){
            msg[cont] = msg[cont] + k;        //para criptografar
        } else if (((msg[cont] + k) > 90) &&  (msg[cont] < 91)){
                msg[cont] = (msg[cont] - 26) + k;
            }
    }

    for (cont = 0; cont < contador; cont++) {
        printf("%c", msg[cont]);
    }

    free(msg);
    return 0;
}
