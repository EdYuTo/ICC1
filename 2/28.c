#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* caracteres(int n) {
    char c, *texto = NULL;
    int cont;

    for(cont = 0; cont < n; ) {
            c = fgetc(stdin);
        if(c != 10) {
    texto = (char*)realloc(texto, sizeof(char)*(cont+1));
    texto[cont++] = c;
    }}
    texto[cont] = '\0';
    return texto;
}

void contagem (char *texto, int *a, int *b) {
    int cont, maiuscula = 0, minuscula = 0, size;
    size = strlen(texto);

    for(cont = 0; cont < size; cont++) {
        if (64<texto[cont] && texto[cont]<91){
            ++maiuscula;
        }
        else if (96<texto[cont] && texto[cont]<123){
            ++minuscula;
        }
    }
    *a = maiuscula;
    *b = minuscula;
    return;
    }

int main()
{
    char *entrada;
    int n, ma = 0, mi = 0;

    scanf("%d", &n);

    entrada = caracteres(n);

    contagem(entrada, &ma, &mi);

    printf("%d %d\n", ma, mi);


    free(entrada);
    return 0;
}
