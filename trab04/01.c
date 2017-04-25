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

FILE *header_reader (char *nome, int *row, int *col, int *max){
	FILE *img;
        char *type, *aux;
        int i, j;

        img = fopen(nome, "r");
        if (img == NULL){
                printf("Cannot open Image, did you write it right?\n");         //Segurança...
                exit(0);
        }

        type = read(img, ENTER);        //Lembrando que para no '\n'
        aux = read(img, SPACE);         //lembrando que para no espaço

        if (aux[FIRST_CHAR] != '#')
                *col = atoi(aux);       //Se for diferente de #, nao tem comentario
        else {
                aux = read(img, ENTER);         //Le o comentario ate '\n'
                fscanf(img, "%d", col);         //Pega o valor de colunas
        }
        fscanf(img, "%d %d", row, max);         //Linhas e o valor maximo

	free(type);
	free(aux);

	return img;	//retornar FILE* para manter o cursor onde ele parou
}

float **create_readM (FILE *img, int row, int col, int n){	//Retornar row, col, max por referencia
	int i, j;
	float **matrix;

	matrix = (float **)calloc((row + n + n), sizeof(float *));
//Pensei em criar uma funcao separada para zerar a "dimensao" extra
//mas do modo que pensei, provavelmente, seria menos efetivo que o calloc

	for (i = 0; i < row + n + n; i++)
		matrix[i] = (float *)malloc((col + n + n) * sizeof(float));

	for (i = n; i < row + n; i++)			//Esse n e usado para gerar um espaco a mais para
		for (j = n; j < col + n; j++)		//operacao com os filtros, ele depende do tamanho
			fscanf(img, "%f", matrix[i]+j); //de cada filtro...

				//PS: Foi criada uma matriz de float para facilitar a operacao com os filtros	
	return matrix;
}

float **create_filter (char *nome, int *dimension){
	FILE *filter;
	float **matrix;

	filter = fopen(nome, "r");
	if (filter == NULL){
		printf("Cannot open filter, did you write it right?\n");
		exit (0);
	}

	fscanf(filter, "%d", dimension);
	
	matrix = create_readM(filter, *dimension, *dimension, 0);

	fclose(filter);

	return matrix;
}
/*
void matrix_zeroing (float **matrix, int row, int col, int n){
	int i, j;

	for (i = n; i < row; i++){
		for (j = 0; j < n; j++)
			matrix[i][j] = 0;
		for (j = col; j < col + n; j++)
			matrix[i][j] = 0;
	}

	for (i = 0; i < n; i++)
		for (j = 0; j < col + n + n; j++)
			matrix[i][j] = 0;
		
	for (i = row; i < row + n; i++)
		for (j = 0; j < col + n + n; j++)
			matrix[i][j] = 0;
		return;
}
*/
void negative (float **matrix, int row, int col, int max){	//Optei por alterar a matriz original
	int i, j;

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			*(*(matrix+i)+j) = max - *(*(matrix+i)+j);	//Inversao das cores

	return;
}
void printM (float **matrix, int row, int col, int n){//Funcao de impressao
	int i, j;
	
	for (i = n; i < row + n; i++){
		for (j = n; j < col + n; j++)
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

float **matrix_convolution (float **img, int row, int col, float **filter, int dim_filter){
	int i, j;
	float**matrix;

}

int main (int argc, char *argv[ ]){
	FILE *aux;
	char *nome;
	int i, row, col, max, filter_dimension = 0; //Inicializado com 0 para o 'free'
	float **img, **filter;
	
	scanf("%d", &i);
	fgetc(stdin);	//Pular o ENTER da entrada...

	if (i == 1){
		nome = read(stdin, ENTER);
		aux = header_reader(nome, &row, &col, &max);
		
		img = create_readM(aux, row, col, 0);
		negative(img, row, col, max);

		printf("P2\n%d %d\n%d\n", col, row, max);	//Nesse caso imprime 'P2'manualmente pois todos os casos sao P2
		printM(img, row, col, 0);		  	 //mas caso necessario, poderia retornar o 'type' da funcao header_reader
	}

	else if (i == 2){
		nome = read(stdin, ENTER);
		aux = header_reader(nome, &row, &col, &max);
			free(nome);
		nome = read(stdin, ENTER);
		
		filter = create_filter(nome, &filter_dimension);
                img = create_readM(aux, row, col, filter_dimension);

                printf("P2\n%d %d\n%d\n", col, row, max);
                printM(img, row, col, filter_dimension);                  

		freeM(filter, filter_dimension);
	}
		
	fclose(aux);
	freeM(img, row + (2 * filter_dimension));
	free(nome);
	return 0;
}
