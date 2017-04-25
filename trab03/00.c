#include <stdlib.h>
#include <stdio.h>

char *read_line(){
	char c, *nome = NULL;
	int i = 0;

	do {
		c = fgetc(stdin); 
		nome = (char *)realloc(nome, sizeof(char)*(i+1));
		*(nome+(i++)) = c;
	}while (c =! 10);
	
	*(nome+(i-1)) = '\0';

	return nome;
}

void read_file (char *nome, unsigned int **v, unsigned int *n){
	FILE *file;
	int i = 0;
	
	*n = 0;

	file = fopen(nome, "r");

	while (!feof) 
		if(!feof){
			n++;
			*v = (unsigned int *)realloc(v, sizeof(int)*(i+1));
			fread(*(v+(i++)), sizeof(int), 1, file);
		}
	
	fclose(file);

	return ;
}

int main (int argc, char *argv[]) {
	char *nome;
	unsigned int *v = NULL, n;

//	nome = read_line();
	
	read_file("0.bin", &v, &n);	

	printf("%d", n);

	free(nome);
	free(v);
	return 0;
}
