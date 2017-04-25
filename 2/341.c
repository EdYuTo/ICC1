#include <stdlib.h>
#include <stdio.h>

void function(int *vec, int k){
	int num, pos;

	do{		
		scanf("%d", &num);
		pos = num%k;
		vec[pos]++;
		
	}while(!feof(stdin));

		vec[pos]--;	//Estava somando um a mais no ultimo...		

	return;
}

void print (int *dado, int k){
	int i, aux = 0;

	for (i = 0; i < k; i++)
		if(dado[i] > aux)
			aux = dado[i];

	for (i = 0; i < k; i++)
		if(dado[i] == aux)
			printf("%d\n", i);

	printf("%d", aux);
	
	return;
}

int main (int argc, char *argv[ ]){
	int *dado = NULL;

	dado = (int *)calloc(7, sizeof(int)); 

	function(dado, 7);

	print(dado, 7);

	free(dado);
	return 0;
}
