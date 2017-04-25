#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void freeM (float **m, int n){
	int i;

	for (i = 0; i < n; i++)
		free(m[i]);
	free(m);

	return;
}

float distance (int n){
	int i;
	float **cord, **center, d;

	cord = (float **)malloc(n * sizeof(float *));
	center = (float **)malloc(1 * sizeof(float *));
	center[0] = (float *)calloc(2 ,sizeof(float));

	for (i = 0; i < n; i++){
		cord[i] = (float *)malloc(2 * sizeof(float));
		scanf("%f %f", cord[i], cord[i]+1);
		if (i > 1){
			center[0][0] += cord[i][0];
			center[0][1] += cord[i][1];
		}
	}
	
	center[0][0] /= (n-1);
	center[0][1] /= (n-1);

	d = pow(**center - **cord, 2) + pow((*(*center)+1) - (*(*cord)+1), 2);
	
	d = sqrt(d);
	
	freeM(center, 1);
	freeM(cord, n);

	printf("%f\n", round(n*d));
}

int main (int argc, char *argv[ ]){
	int n;

	scanf("%d", &n);
	
	distance(n);

	return 0;
}
