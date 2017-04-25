#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float *read (int *i){
	float *n = NULL;	

	*i = 0;		

	while (!feof(stdin))
		if (!feof(stdin)){
			n = (float *)realloc(n, sizeof(float) * (*i + 1));
			scanf("%f", n+(*i)++);	
		}
	(*i)--;

	return n;
}

void printv (float *vec, int len){
	int i;

	for (i = 0; i < len; i++)
		printf("%.2f ", vec[i]);	
	printf("\n");

	return;
}

void variancia (float *vec, float *media, int len){
	int i;
	float *var = (float *)malloc(len *sizeof(float));
	
	var[0] = (vec[0] - media[0])*(vec[0] - media[0]) + 
		(vec[1] - media[0])*(vec[1] - media[0]);
		//1 0 3 8 2	
		//0.50 1.33 3.00 2.80
	for (i = 1; i < len; i++){
		var[i] = (i/(i+1)) * (var[i-1] * var[i-1]) +
			(vec[i+1]-media[i-1])*(vec[i+1]-media[i-1])/(i+1);
		var[i] = sqrt(var[i]);		
	}

	printv(var, len);

	free(var);

	return; 
}

void media (float *vec, int len){
	int i;
	float *media = (float *)malloc((len-1) * sizeof(float));

	media[0] = (vec[1] + vec[0])/2;
		//1 0 3 8 2
		//0 1 2 3 4
	for (i = 1; i < len-1; i++)
		media[i] = media[i-1] + (vec[i+1] - media[i-1])/(i+2);
	
	printv(media, len-1);
	
	variancia(vec, media, len-1);	

	free(media);

	return;
}

int main (int argc, char *argv[ ]){
	int len;
	float *n;

	n = read(&len);

	media(n, len);

	free(n);

	return 0;
}
