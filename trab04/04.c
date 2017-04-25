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

float **create_readM (FILE *img, int row, int col){
	int i, j;
	float **matrix;

	matrix = (float **)calloc(row, sizeof(float *));

	for (i = 0; i < row; i++)
		matrix[i] = (float *)malloc(col * sizeof(float));

	for (i = 0; i < row; i++)		
		for (j = 0; j < col; j++)
			fscanf(img, "%f", matrix[i]+j);

				//PS: Foi criada uma matriz de float para facilitar a operacao com os filtros	
	return matrix;
}

float **create_filter (char *nome, int *dimension){	//Funcao separada para nao ter de passar um
	FILE *filter;					//arquivo FILE da main para creat_readM
	float **matrix;

	filter = fopen(nome, "r");
	if (filter == NULL){
		printf("Cannot open filter, did you write it right?\n");
		exit (0);
	}

	fscanf(filter, "%d", dimension);
	
	matrix = create_readM(filter, *dimension, *dimension);

	fclose(filter);

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
			printf("%d ",(int) *(*(matrix+i)+j));
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

float aux_convolution (float **img, float **filter, int filter_dim, int row, int col, int min, int *gmax, int *gmin){
	int i, j, sum = 0;

	for (i = 0; i < filter_dim; i++)
		for (j = 0; j < filter_dim; j++)
			if (row >= min + i && col >= min + j)
				sum += filter[i][j] * img[row - i][col - j];	//Convolucao unitaria

	if (*gmax < sum)	*gmax = sum;	//Maior valor passado por referencia
	else if (*gmin > sum)	*gmin = sum;	//Menor valor passado por referencia
			
	return sum;
}

float **matrix_convolution (float **img, int row, int col, float **filter, int filter_dim, int max){
	int i, j, min, gmax = 0, gmin = 0;
	float **matrix;		
	
	min = filter_dim/2;

	matrix = (float **)malloc(row * sizeof(float *));

	for (i = 0; i < row; i++)
		matrix[i] = (float *)malloc(col *  sizeof(float));

	for (i = 0; i < row; i++)		//>>>Algo errado!--esta deslocando a imagem um pouco...
		for (j = 0; j < col; j++)
			matrix[i][j] = aux_convolution(img, filter, filter_dim, i, j, min, &gmax, &gmin);	//Convolucao

	for (i = 0; i < row; i++)		//Normatizacao
		for (j = 0; j < col; j++)
			matrix[i][j] = ((matrix[i][j] - gmin) / (gmax - gmin)) * max;
										//Max = maior valor possivel da imagem!
	return matrix;
}

int main (int argc, char *argv[ ]){
	FILE *aux;
	char *nome;
	int i, row, col, max, filter_dimension;
	float **img, **filter, **new_img;
	
	scanf("%d", &i);
	fgetc(stdin);	//Pular o ENTER da entrada...

	if (i == 1){
		nome = read(stdin, ENTER);
		aux = header_reader(nome, &row, &col, &max);
		
		img = create_readM(aux, row, col);
		negative(img, row, col, max);

		printf("P2\n%d %d\n%d\n", col, row, max);	//Nesse caso imprime 'P2'manualmente pois todos os casos sao P2
		printM(img, row, col);		  	 	//mas caso necessario, poderia retornar o 'type' da funcao header_reader
	}

	else if (i == 2){
		nome = read(stdin, ENTER);
		aux = header_reader(nome, &row, &col, &max);	//Abre um aqruivo com a matriz img
			free(nome);		//Para poder pegar o nome do filtro
		nome = read(stdin, ENTER);	//
		
		filter = create_filter(nome, &filter_dimension);	//Gera matriz de filtro
                img = create_readM(aux, row, col);	//Gera matriz de imagem

		new_img = matrix_convolution(img, row, col, filter, filter_dimension, max);	//Gera matriz "operada"

                printf("P2\n%d %d\n%d\n", col, row, max);
                printM(new_img, row, col);                  

		freeM(filter, filter_dimension);
		freeM(new_img, row);
	}
	
	if (i == 1 || i == 2){	//Evitar double free caso i != 1 ou 2
		fclose(aux);
		freeM(img, row);
		free(nome);
	}

	return 0;
}
