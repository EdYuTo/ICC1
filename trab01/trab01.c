//EDSON YUDI TOMA  9791305

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *read() {
    char c, *msg =NULL;
    int contador = 0;

    do {c = fgetc(stdin);
        msg = (char *)realloc(msg, sizeof(char)*(contador+1));
        msg[contador++] = c;
    } while (c != 10);
    msg[--contador] = '\0';

    return msg;
}

char *cesar(int k, char*msg) {
    int cont, contador;
    contador = strlen(msg);

    for (cont = 0; cont < contador; cont++){
        if ((64 < msg[cont] && msg[cont] < (91 - k))){
            msg[cont] = msg[cont] + k;        //para criptografar
        } else if (((msg[cont] + k) > 90) &&  (msg[cont] < 91)){
                msg[cont] = (msg[cont] - 26) + k;
            }
    }
    return msg;
}

void print (char *msg) {
        int cont, contador;
        contador = strlen(msg);

        for (cont = 0; cont < contador; cont++) {
        printf("%c", msg[cont]);
    } printf("\n");
    return;
}

char *vigenere(char*msg, char*chave) {
     int contador, cont, cont1 = 0;
     contador = strlen(msg);

   for (cont = 0; cont < contador; cont++){
            if (cont1 < strlen(chave)) {
        if ((64 < msg[cont] && msg[cont] < (156 - chave[cont1]))){
            msg[cont] = msg[cont] + chave[cont1] - 65;
		cont1++;							    //criptografando..
        } else if (((msg[cont] + chave[cont1]) > 155) &&  (msg[cont] < 91)){
                msg[cont] = msg[cont] + chave[cont1]-91;
		cont1++;
            } }
            else {cont1 = 0;
            cont--;
            }
    }
    return msg;
}
int main (int argc, char* argv[]){
        char c, *msg = NULL, *chave = NULL;
        int k, l;

    do{c = fgetc(stdin);}while(c != 10);    // Para saltar a quantidade de digitos

    msg = read();

    scanf("%d", &l);

    scanf("%d", &k);

    if (l==1){

    msg = cesar(k, msg);
    print(msg);
    }

    else if (l==2){
    do{c = fgetc(stdin);}while(c != 10); //Para saltar o enter da entrada

    chave = read();

    msg = vigenere(msg, chave);

    print(msg);
    }

free(msg);
free(chave);
return 0;
}
