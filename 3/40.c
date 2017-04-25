#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *read ( ){
	char *texto = NULL;
	int i = 0;

	do {	
		texto = (char *)realloc(texto, sizeof(char)*(1+i));
		texto[i++] = fgetc(stdin);

	}while (texto[i - 1] != 10);
	
	texto[i - 1] = '\0';

	return texto;
}

void print (char *texto){
	int i, j;

	i = strlen(texto);

	for (j = 0; j < i; j++)
		printf("%c\n", texto[j]);
	
	return;
}

int main (int argc, char *argv[ ]){
	char *texto;

	texto = read( );

	print(texto);

	free(texto);

	return 0;
}
