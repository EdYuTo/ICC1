#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[ ]){
	int i, j, n, *pascal, *aux;

	scanf("%d", &n);

	pascal = (int *)calloc(n,  sizeof(int));
	aux = (int *)calloc(n, sizeof(int));
	pascal[0] = 1;
	aux[0] = 1;

	for (i = 1; i <= n; i++){
		for (j = 0; j < i; j++){
			pascal[j] = aux[j] + aux[j-1];
			printf("%u", pascal[j]);
		}
		for (j = 0; j < i; j++)
			aux[j] = pascal[j];
		printf("\n");
	}
	
	free(pascal);
	free(aux);
	return 0;
}
