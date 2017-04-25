#include <stdlib.h>
#include <stdio.h>

int rep (char *texto, char palavra, int size){
	int i, n = 0;

	for (i = 0; i < size; i++)
			if (palavra == texto[i]) n++;	
	
	return n;
}


int main (){
	char *texto = NULL, c;
	int i = 0, repetem;

	do {			
		c = fgetc(stdin);
		texto = (char *)realloc(texto, sizeof(char)*(i+1));	
		texto[i++] = c;		
	}while (c != 10);		
	
		c = fgetc(stdin);
		fgetc(stdin);	
	
	repetem = rep(texto, c, i); 
	
	printf("%d", repetem);	
	
	free(texto);	

	return 0;
}
