#include <stdlib.h>
#include <stdio.h>

char *read() {
	char c, *nome = NULL;
	int i = 0;

	do {
		c = fgetc(stdin);
		nome = (char *)realloc(nome, sizeof(char)*(i+1));
		nome[i++] = c;

	} while (c != 10);
	
	nome[i-1] = '\0';
	
	return nome;	
}

unsigned int *invert(unsigned int *v, int n){
	unsigned int *inv, i;
		
	inv = (unsigned int *)malloc(sizeof(int)*n);
		
	for (i = 0; i <= n; i++)
		inv[i] = v[n-i];	
	
	free(v);	
	return inv;
}

unsigned int *read_file(char *nome, int *n) {
	FILE *file;
	unsigned int i = 0, *v = NULL;

	file = fopen(nome, "r");
	
	do{
		if(!feof(file)){
			v = (unsigned int *)realloc(v, sizeof(int)*(*n+1));
			fread((v+((*n)++)), sizeof(int), 1, file);	
		}
	}while (!feof(file));

	fclose (file);

	v = invert(v, *n);

	return v;
}




int main (int argc, char *argv[ ]){
	char *nome;
	unsigned int *v, n = 0;
	int a;

	nome = read();

	v = read_file(nome, &n);

	printf("%s\n%d\n", nome, n);	

	for (a = 0; a <= n; a++) printf("%u\n", v[a]);	
	
	free(nome);
	free(v);
	return 0;
}
