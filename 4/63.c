#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double *tribonacci (int n) {
	int i;
	double *seq;

	if (n > 3) {
		seq = (double *)malloc(n * sizeof(double));
		seq[0] = seq[1] = 0;
		seq[2] = 1;
		
		for (i = 3; i < n; i++)
			seq[i] = seq[i-3] + seq[i-2] + seq[i-1];
	}

	else if (n == 2) {
		seq = (double *)malloc(n * sizeof(double));
		seq[0] = seq[1] = 0;
	}
	
	else if (n == 1) {
		seq = (double *)malloc(n * sizeof(double));
		seq[0] = 0;
	}
	
	else seq = NULL;

	return seq;
}

double media (double *seq, int n, int start) {
	int i;
	double sum = 0;

	for (i = start; i < n; i++)
		sum += seq[i];

	return sum/n;
}

void printSeq (double *seq, int n) {
	int i;

	for (i = 0; i < n; i++)
		printf("%.1lf ", seq[i]);
	printf("\n");

	return;
}

double pearson (double *seq, int n) {
	int i;
	double m1half, m2half, cov, div;

	m1half = media(seq, n/2, 0);
	m2half = media(seq, n, n/2);

	for (i = 0; i < n/2; i++){
		cov = (seq[i] - m1half) * (seq[i + n/2] - m2half);
		div = pow((seq[i] - m1half), 2) *
			 pow((seq[i + n/2] - m2half), 2);
	}

	return cov/sqrt(div);	
}

int main (int argc, char *argv[ ]){
	int n, opt;
	double *seq, aux;

	scanf("%d %d", &opt, &n);

	seq = tribonacci(n);
		
	switch (opt) {
		case 1:
			printSeq(seq, n);
			break;
		case 2:
			aux = media(seq, n, 0);
			printf("%.4lf ", aux);
			break;
		case 3:
			aux = pearson(seq, n);
			printf("%.4lf ", aux);
			break;
	}

	free(seq);
	return 0;
}

