#include <stdlib.h>
#include <stdio.h>

#define ENTER 10
#define SPACE 32
#define FIRST_CHAR 0

char *readline (FILE *stream, char terminator){	//Readline generica...
	char c, *text = NULL;
	int i = 0;

	do {
		c = fgetc(stream);
		text = (char *)realloc(text, sizeof(char) * (i+1));
		text[i++] = c;

	} while (c != terminator);

	text[--i] = '\0';

	return text;
}

int **create_readM (char *nome, int *row, int *col, int *max, char **type){	//Retornar row e col por referencia
	FILE *img;
	char *aux;
	int i, j, **matrix;

	img = fopen(nome, "r");
	if (img == NULL){
		printf("Cannot open Image, did you write it right?\n");		//Segurança...
		exit(0);
	}

	*type = readline(img, ENTER);		//Lembrando que para no '\n'
	aux = readline(img, SPACE);		//lembrando que para no espaço

	if (aux[FIRST_CHAR] != '#')	
		*col = atoi(aux);	//Se for diferente de #, nao tem comentario
	else {		
		aux = readline(img, ENTER);		//Le o comentario ate '\n'
		fscanf(img, "%d", col);		//Pega o valor de colunas
	}
	fscanf(img, "%d %d", row, max);		//Linhas e o valor maximo

	matrix = (int **)malloc((*row) * sizeof(int *));	//
								//
	for (i = 0; i < *row; i++)				//->Declaracao
		matrix[i] = (int *)malloc((*col) * sizeof(int));//
								
	for (i = 0; i < *row; i++)				//
		for (j = 0; j < *col; j++)			//->Leitura
			fscanf(img, "%d", matrix[i]+j);		//

	fclose(img);
	free(aux);
				
	return matrix;
}

void printPGM (int row, int col, int max, char *type, int **img){//Impressao
	int i, j, check, count;

	printf("P8\n%d %d\n%d\n", col, row, max);

	for (i = 0; i < row; i++){
		check = img[i][0];
		for (j = 0; j < col; j++){
			for (count = 1; check == img[i][j] && j+1 < col; count++, j++);
			if (count < 4){
				for ( ; count >=1; count--)
					printf("%d ", img[i][j-count+1]);
			}
			else
				printf("@ %d %d ", check, count);
			check = img[i][j];
		}	
		printf("\n");
	}

	return;
}

void freeM (int **img, int row){	//Liberacao da matriz
	int i;

	for (i = 0; i < row; i++)
		free(img[i]);

	free(img);

	return;
}

int main (int argc, char *argv[ ]){
	char *in, *type; 
	int value, row, col, max, **img;	

	in = readline(stdin, ENTER);
	img = create_readM(in, &row, &col, &max, &type);
	
	printPGM(row, col, max, type, img);

	freeM(img, row);
	free(in);
	free(type);
	
	return 0;
}
