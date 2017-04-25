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

}

int **function(int **vec, int k){
	int j = 0, num, pos;

	do{	
		scanf("%d", &num);
		pos = num%k;
			while(vec[pos][j] != - 1) j++;
		vec[pos] = (int*)realloc(vec[pos], sizeof(int)*(j+2));
		vec[pos][j++] = num;
		vec[pos][j] = -1;
		j = 0;
	}while(!feof(stdin));

		pos = num%k;
			while(vec[pos][j] != -1) j++;
		vec[pos][--j] = - 1;		

	return vec;
}

int size (int **vec, int i){
	int len = 0;
		
	while(vec[i][len] != -1) len++;

	return len;
}

void printvec (int **vec){
	int i, j, len = 0, *max;

	for(i = 0; i < 6; i++)	{
		printf("%d: ", i);
		while(vec[i][len] != -1) len++;
			for(j = 0; j < len; j++) 
				printf("%d ", vec[i][j]);
		printf("\n");
	len = 0;		
	}
	
	max = calloc(7, sizeof(int));
	
	for (i = 0, j = 0; i < 5; i++){
	printf("size: %d\n", size(vec, i));
		if (size(vec, i) > len){
			max[j] = vec[i][0];
			len = size(vec, i);
		}
		else if (size(vec, i+1) == len) max[++j] = vec[i][0];
		
		max[j+1] = len;
	}
	
	for (i = 0; i <= j+1; i++)
		printf("%d\n", max[j]);
	
	free(max);
	return;
}

void freevec (int **vec){
	int i;
	
	for (i = 0; i < 6; i++)
		free(vec[i]);	
	free(vec);

	return;
}

int main (int argc, char *argv[ ]){
	int **dado = NULL;

	dado = createv(dado, 6);

	dado = function(dado, 6);

	printvec(dado);

	
	freevec(dado);				
	
	return 0;
}
