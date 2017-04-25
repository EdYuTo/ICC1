#include <stdlib.h>
#include <stdio.h>
float  * read (float *vec, int n){
	int i, j;
	float aux;

	for (i = 0; i < n; i++)
		scanf("%f", vec+i);

	for (i = 0; i < n-1; i++)
		for (j = 1 + i; j < n; j++)
			if(vec[i] > vec[j]){
				aux = vec[j];
				vec[j] = vec[i];
				vec[i] = aux;
			}
	return vec;
}

void print (float *vec, int n){
	int i, j, cont;

	for (i = 0; i <= n-1; i++){
		for (j = 1 + i, cont = 1; j < n; j++)
			if(*(vec+i) == *(vec+j)){
				cont++;
				i++;
		}

		printf("%.1f %d\n", *(vec+i), cont);
	}

	return;
}

int main (int argc, char *argv[ ]){
	int n;
	float *seq;
	
	scanf("%d", &n);

	seq = (float *)malloc(n*sizeof(float));

	seq = read(seq, n);
	
	print(seq, n);

	free(seq);

	return 0;
}
