#include <stdlib.h>
#include <stdio.h>

char *rl() {
	char c, *nome = NULL;
	int i = 0;

	do {
		c = fgetc(stdin);
		nome = realloc(nome, sizeof(char)*(i+1));
		nome[i++] = c;
	}while(c!=10);

	nome[--i] = '\0';

	return nome;
}

int main (int argc, char *argv[ ]) {
	FILE *file;
	char *c;
	int i;

	c = rl();

	file = fopen(c, "r");
	
	i = ftell(file);
	
	printf("%d\n", i);

	fseek(file, 4, SEEK_END);

	i = ftell(file);

	printf("%d\n", i);

	fclose(file);

	return 0;
}
