/*EDSON YUDI TOMA -- 9791305*/

#include <stdlib.h>
#include <stdio.h>

int **createv(int **vec, int k){
	int i;

	vec = (int**)malloc(sizeof(int*)*k);	
	
	for (i = 0; i < k; i++){
		vec[i] = (int*)malloc(sizeof(int)*1);
		vec[i][0] = -1;
	}
	return vec;

/* A ideia da função createvector é alocar um espaço na heap com a base de k elementos onde ficarão armazenados os vetores com os números...
O '-1' foi usado como terminador para a contagem do tamanho do vetor para facilitar a realocação.
*/

}

int **function(int **vec, int n, int k){
	int i, j = 0, num, pos;

	for (i = 0; i < n; i++){
		scanf("%d", &num);
		pos = num%k;
			while(vec[pos][j] != -1) j++;
		vec[pos] = (int*)realloc(vec[pos], sizeof(int)*(j+2));
		vec[pos][j++] = num;
		vec[pos][j] = -1;
		j = 0;
	}

	return vec;

/* A ideia da função é escanear n elementos digitados e armazená-los na posição 'N mod K' utilizando '-1' como base para contar o tamanho do vetor e realocar j (tamano inicial) + 2(novo elemento e terminador -1)
*/
}

void printv(int **vec, int k) {
	int i, j, len = 0;

	for(i = 0; i < k; i++)	{
		printf("%d: ", i);
		while(vec[i][len] != -1) len++;
			for(j = 0; j < len; j++) 
				printf("%d ", vec[i][j]);
		printf("\n");
	len = 0;		
	}

	return;

// PRINT THEM ALL!
}

int main (int argc, char *argv[ ]){
	int k, n, **saida = NULL;

	scanf("%d %d", &k, &n);
	
	saida = createv(saida, k);
	
	saida = function(saida, n, k);

	printv(saida, k);

	for (n = 0; n < k; n++) //FREE THEM ALL!
		free(saida[n]);	
	free(saida);

	return 0;
}
