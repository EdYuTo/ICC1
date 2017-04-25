#include <stdlib.h>
#include <stdio.h>

char *read( ){
	char c, *nome = NULL;
	int i = 0;

	do{
		c = fgetc(stdin);
		nome = (char *)realloc(nome, sizeof(char) * (i + 1));
		nome[i++] = c;

	} while (c != '\n');
	
	nome[--i] = '\0';

	return nome;
}

int main (int argc, char *argv[ ]){
	char *nome;
	FILE *fp;
	int size;

	nome = read( );

	fp = fopen(nome, "r");

	fseek(fp, 0, SEEK_END);

	size = ftell(fp);

	printf("%d\n", size);

	fclose(fp);
	free(nome);

	return 0;
}
