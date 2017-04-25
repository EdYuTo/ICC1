#include <stdlib.h>
#include <stdio.h>

int main()
{
    char c, *cadeia = NULL;
    int cont = 0, cont1, alfabeto = 0, numerico = 0;

    do {
        c = fgetc(stdin);
        cadeia = (char*)realloc(cadeia, sizeof(char)*(cont+1));
        cadeia[cont++] = c;
    } while (c != 10);
        cont--;

    for (cont1 = 0; cont1 < cont; cont1++) {
        if ((64<cadeia[cont1] && cadeia[cont1]<91) || (96<cadeia[cont1] && cadeia[cont1]<123)){
            alfabeto++;
        } else if (47<cadeia[cont1]&&cadeia[cont1]<58){
            numerico++;
        }
    }
    printf("%d\n%d", alfabeto, numerico);
    free(cadeia);
    return 0;
}
