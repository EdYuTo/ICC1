#include <stdlib.h>
#include <stdio.h>

struct agenda{
	int dia, mes, ano, hora, minuto, segundo;
	char *nota;
};

char *read ( ){
	int i = 0;
	char c, *text = NULL;

	do{
		c = fgetc(stdin);
		text = (char *)realloc(text, sizeof(char) * (i + 1));
		text[i++] = c;

	} while (c != 10);

	text[--i] = '\0'; 

	return text;
}

void preench (struct agenda *dados, int n){
	int i;

	for (i = 0; i < n; i++){
		scanf("%d %d %d", &dados[i].dia, &dados[i].mes, &dados[i].ano);
		scanf("%d %d %d", &dados[i].hora, &dados[i].minuto, &dados[i].segundo);
		fgetc(stdin);
		dados[i].nota = read();

	}	

	return;
}

void printS (struct agenda *dados, int n){
	int i;
	
	for (i = 0; i < n; i++){
		printf("%02d/%02d/%02d ", dados[i].dia, dados[i].mes, dados[i].ano);
		printf("- %02d:%02d:%02d", dados[i].hora, dados[i].minuto, dados[i].segundo);
		printf("\n%s\n", dados[i].nota);
	}

	return;
}
int main (int argc, char *argv[ ]){
	int i, n;
	struct agenda *x;

	scanf("%d", &n);

	x = (struct agenda *)malloc(n * sizeof(struct agenda));
		
	preench(x, n);
	printS(x, n);

	for (i = 0; i < n; i++)
		free(x[i].nota);
	free(x);
}
