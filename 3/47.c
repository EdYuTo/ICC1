#include <stdlib.h>
#include <stdio.h>


int **generate (int row, int col){
	int i, **mat;

	mat = (int **)malloc(row * sizeof(int *));

	for (i = 0; i < row; i++)
		mat[i] = (int *)calloc(col, sizeof(int));

	return mat;
}

void readM (int **mat, int row, int col){
	int i, j;

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			scanf("%d", mat[i]+j);
	return;
}

int **mat_mult (int **mat1, int row1, int col1, int **mat2, int row2, int col2){
	int i, j, k, **mat;

	if (col1 != row2)	
		return NULL;

	else{
		mat = generate(row1, col2);

		for (i = 0; i < row1; i++)
			for (j = 0; j < col2; j++)
				for (k = 0; k < col1; k++)
					mat[i][j] += mat1[i][k] * mat2[k][j]; 	
	}

	return mat;
}

void freeM (int **mat, int row){
	int i;

	for (i = 0; i < row; i++)
		free(mat[i]);

	free(mat);

	return;

}

void printM (int **mat, int row, int col){
	int i, j;

	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	return;
}

int main (int argc, char *argv[ ]){
	int i, j, k, l, **mat1, **mat2, **result;

	scanf("%d %d", &i, &j);	

	mat1 = generate (i, j);
	readM(mat1, i, j);

	scanf("%d %d", &k, &l);

	mat2 = generate (k, l);
	readM(mat2, k, l);

	result = mat_mult (mat1, i, j, mat2, k, l);
	if(result !=  NULL)
		printM(result, i, l);	

	freeM(mat1, i);
	freeM(mat2, k);
	if(result !=  NULL)
		freeM(result, i);
	
	return 0;
}
