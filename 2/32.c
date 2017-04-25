#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[ ]){
	int n, i = 31, *bin;

	scanf("%d", &n);

	bin = (int *)calloc(32, sizeof(int));
		
	while (n != 1){
		bin[i--] = n%2;
		n /= 2;
	}
	
	bin[i] = n;

	for (i = 0; i < 32; i++)
		printf("%d", bin[i]);
	
	free(bin);	
	
	return 0;
}
