#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *name ( ){
	char *nome = NULL;	
	int i = 0;

	do{
		nome = (char *)realloc(nome, sizeof(char)*i+1);
		nome[i++] = fgetc(stdin);

	}while (nome[i-1] != 10);

	nome[i-1] = '\0';
	
	return nome;
}

char **tokenize (char *string, int *i){
	char *token, **tok = NULL;
	int j, k;
	
	*i = 0;

	token = strtok(string, " ");
	tok = (char **)realloc(tok, sizeof(char *) * (*i+1));
	tok[(*i)++] = token;

	while (token != NULL){
		token = strtok(NULL, " ");
		tok = (char **)realloc(tok, sizeof(char *) * (*i+1));
		tok[(*i)++] = token;
	}
	
	k = *i - 1;
	
	token = tok[k-1];

	while (k > 1){
		tok[k-1] = tok[k-2];	//-1 a mais para evitar acessar endereço invalido
		k--;			//troca os nomes.. 2 vira 3, 3 - 4 ... n-1 -> n
	}

	tok[0] = token;			//por fim, n vem para posicao 0
	
	//free(token); ---> enderecos na string...
	return tok;	
}

void to_upp (char *string){
	int i, len;

	len = strlen(string);

	for (i = 0; i < len; i++)
		if (97 <= string[i] && string[i] <= 122)
			string[i] -= 32;
	return;
}

void print (char **string, int len){
	int i;

	to_upp(string[0]);

	printf("%s, ", string[0]);	

	for (i = 1; i < len-1; i++)
		printf("%s ", string[i]);

	return;
}

int main (int argc, char *argv[ ]){
	char *nome, **tok;
	int i;

	nome = name();
	
	tok = tokenize(nome, &i);

	print(tok, i);

	free(nome);
	free(tok);

	return 0;
}
