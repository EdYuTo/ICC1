#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float **cord (int i){
	int j, k;
	float **m = (float **)malloc(i * sizeof(float*));

	for (j = 0; j < i; j++){
		m[j] = (float *)malloc(2 * sizeof(float));
		for (k = 0; k < 2; k++)
			scanf("%f", m[j]+k);
	}

	return m;
}

void pcv (float **m, int n){
	int i, j;
	float d = 0, aux1 = 0, aux;

	for (i = 0; i < n; i++){
	aux = sqrt(pow(m[i][0]-m[(i+1)%n][0], 2)
				+pow(m[i][1]-m[(i+1)%n][1], 2));
		for (j = i; j < n; j++){
			aux1 = sqrt(pow(m[i][0]-m[j][0], 2)
				+pow(m[i][1]-m[j][1], 2));
			if(aux1 <= aux)
				aux = aux1;
		}
		d += aux;
	}
	
	printf("%f\n", aux);
	
	return;
}

void freev(float **m, int i){
	int j;

	for (j = 0; j < i; j++)
		free(m[j]);

	free(m);

	return;
}

int main (int argc, char *argv[ ]){
	int i;
	float **m;

	scanf("%d", &i);

	m = cord(i);

	pcv(m, i);

	freev(m, i);

	return 0;
}
