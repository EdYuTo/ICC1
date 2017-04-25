#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct dados{
	char *cpf, *nome;
	int idade;
};

char *read (FILE *stream){
        int i = 0;
        char c, *text = NULL;

        do{
                c = fgetc(stream);
                text = (char *)realloc(text, sizeof(char) * (i + 1));
                text[i++] = c;

        } while (c != 10 && c != EOF);

        text[--i] = '\0';

        return text;
}

struct dados *readS (struct dados *anterior, char *nome, int *i){
	FILE *fp;
	struct dados *pessoa;
	
	pessoa = anterior;

	fp = fopen(nome, "r");
		if (fp == NULL){
			printf("Oops, something went wrong...");
			exit(0);
		}

	while (!feof(fp))
		if(!feof(fp)){
			pessoa = (struct dados *)realloc(pessoa, sizeof(struct dados) * (*i + 1));
			pessoa[*i].cpf = read(fp);
			pessoa[*i].nome = read(fp);
			scanf("%d", &pessoa[*i].idade);
			(*i)++;
		}

	fclose(fp);

	return pessoa;
}

void order (struct dados *pessoa, int n){
	int i, j;
	struct dados aux;

	for (i = 0; i < n-1; i++)
		for (j = i; j < n; j++)
			if (strcmp(pessoa[i].cpf, pessoa[j].cpf) > 0){
				aux = pessoa[i];
				pessoa[i] = pessoa[j];
				pessoa[j] = aux;
			}
	return;
}

void print (struct dados *pessoa, int n){
	int i;
	
	for (i = 0; i < n; i++)
		printf("%s\n%s\n%d\n", pessoa[i].cpf, pessoa[i].nome, pessoa[i].idade);

	return;
}

void freeS (struct dados *pessoa, int n){
	int i;

	for (i = 0; i < n; i++){
		free(pessoa[i].cpf);
		free(pessoa[i].nome);
	}
	free(pessoa);
	
	return;
}

int main (int argc, char *argv[ ]){
	char *nome;
	int i = 0;
	struct dados *x1 = NULL;
	
	nome = read(stdin);
	x1 = readS(x1, nome, &i);
	free(nome);

	nome = read(stdin);
	x1 = readS(x1, nome, &i);
	free(nome);
	
	order(x1, i);
	print(x1, i);
	freeS(x1, i);

	return 0;
}
