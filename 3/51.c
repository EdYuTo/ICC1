#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (int argc, char *argv[ ]){
	int n, k, i, j, *vec;

	scanf("%d", &n);

	k = (int)floor(sqrt(n));

	vec = (int *)malloc(n * sizeof(int));

	vec[0] = 2;
	
	for (i = 1, j = 2; i < n; i++)
		vec[i] = j++;
	
	for (i = 1; i <= k; i++){
		for (j = 1; j < n; j++)
			if (vec[j] != 1 && vec[i-1] != 1)
				printf("%d ", vec[j]);

		if (vec[i] != 1)printf("\n");
		
		for (j = i+1; j < n; j++)
			if (!(vec[j]%vec[i]) && vec[i] != 1)
				vec[j] = 1;
	}	

	free(vec);

	return 0;
}
