//------9791305------

#include <stdlib.h>
#include <stdio.h>

#define ENTER 10
#define SPACE 32
#define FIRST_CHAR 0

char *read (FILE *stream, char terminator){//read_line um pouco mais generica (de/ate onde ler)
	char c, *nome = NULL;
	int i = 0;

	do{
		c = fgetc(stream);
		nome = (char *)realloc(nome, sizeof(char) * (i + 1));
		nome[i++] = c;

	} while (c != terminator);	//Parar no terminador passado como argumento
	
	nome[--i] = '\0';
	
	return nome;
}

float **create_readM (char *nome, int *row, int *col, int *max){	//Retornar row, col, max por referencia
	FILE *img;
	char *type, *aux;
	int i, j;
	float **matrix;

	img = fopen(nome, "r");
	if (img == NULL){
		printf("Cannot open Image, did you write it right?\n");		//Segurança...
		exit(0);
	}

	type = read(img, ENTER);	//Lembrando que para no '\n'
	aux = read(img, SPACE);		//lembrando que para no espaço

	if (aux[FIRST_CHAR] != '#')	
		*col = atoi(aux);	//Se for diferente de #, nao tem comentario
	else {		
		aux = read(img, ENTER);		//Le o comentario ate '\n'
		fscanf(img, "%d", col);		//Pega o valor de colunas
	}
	fscanf(img, "%d %d", row, max);		//Linhas e o valor maximo

	matrix = (float **)malloc((*row) * sizeof(float *));

	for (i = 0; i < *row; i++)
		matrix[i] = (float *)malloc((*col) * sizeof(float));

	for (i = 0; i < *row; i++)
		for (j = 0; j < *col; j++)
			fscanf(img, "%f", matrix[i]+j);

	fclose(img);
	free(type);
	free(aux);
				//PS: Foi criada uma matriz de float para facilitar a operacao com os filtros	
	return matrix;
}

void negative (float **matrix, int row, int col, int max){	//Optei por alterar a matriz original
	int i, j;

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			*(*(matrix+i)+j) = max - *(*(matrix+i)+j);	//Inversao das cores

	return;
}
void printM (float **matrix, int row, int col){//Funcao de impressao
	int i, j;
	
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++)
			printf("%.0f ", *(*(matrix+i)+j));
		printf("\n");
	}
	return;
}
void freeM (float **matrix, int row){//Liberacao da matriz
	int i;

	for (i = 0; i < row; i++)
		free(*(matrix+i));
	free(matrix);

	return;
}

int main (int argc, char *argv[ ]){
	char *nome;
	int i, row, col, max;
	float **img;
	
	scanf("%d", &i);
	fgetc(stdin);
	if (i == 1){
		nome = read(stdin, ENTER);
		img = create_readM(nome, &row, &col, &max);
		printf("P2\n%d %d\n%d\n", col, row, max);	//Nesse caso imprime 'P2'manualmente pois todos os casos sao P2
		negative(img, row, col, max);			//mas caso necessario, poderia retornar o 'type' da funcao creat_readM
		printM(img, row, col);
		freeM(img, row);
		free(nome);
	}
		
	return 0;
}
