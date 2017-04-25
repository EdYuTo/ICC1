#include <stdlib.h>
#include <stdio.h>

int **criar_quadrado (int n){		
	int i, j, **quadrado;
	
	quadrado = (int **)malloc(n * sizeof(int *));

	for (i = 0; i < n; i++){
		quadrado[i] = (int *)malloc(n * sizeof(int));
		for (j = 0; j < n; j++)
			scanf("%d", quadrado[i]+j);
	}

	return quadrado;
}

int line (int **quadrado, int i, int n){
	int j, sum = 0;

	for (j = 0; j < n; j++)
		sum += quadrado[i][j];

	return sum;
}

int col (int **quadrado, int i, int n){
	int j, sum = 0;

	for (j = 0; j < n; j++)
		sum += quadrado[j][i];

	return sum;
}

int diag1 (int **quadrado, int n){
	int i, sum = 0;

	for (i = 0; i < n; i++)
		sum += quadrado[i][i];

	return sum;
}

int diag2 (int **quadrado, int n){
	int i, sum = 0;

	for (i = 0; i < n; i++)
		sum += quadrado[i][n-1-i];

	return sum;
}

void check (int **quadrado, int n){
	int i, j = 0;
	
	for (i = 0; i < n; i++)
		if (line(quadrado, i, n) == col(quadrado, i, n) && col(quadrado, i, n) == diag1(quadrado, n)
				 && diag1(quadrado, n) == diag2(quadrado, n))
			j++;
	
	
	if (j == i)
		printf("SIM");
	else
		printf("NAO");
	return;
}

void free_quadrado (int **quadrado, int n){
	int i;

	for (i = 0; i < n; i++)
		free(quadrado[i]);

	free(quadrado);

	return;
}

int main (int argc, char *argv[ ]){
	int n, **quadrado;

	scanf("%d", &n);

	quadrado = criar_quadrado(n);

	check(quadrado, n);
	
	free_quadrado(quadrado, n);

	return 0;
}
