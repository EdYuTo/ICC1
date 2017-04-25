//EDSON YUDI TOMA 9791305 -- BETA VERSION

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *read() {
	char c, *nome = NULL;
	int i = 0;

	do {
		c = fgetc(stdin);
		nome = (char *)realloc(nome, sizeof(char)*(i+1));
		nome[i++] = c;

	} while (c != 10);
	
	nome[i-1] = '\0';
	
	return nome;	
}

unsigned int *invert(unsigned int *v, int n){
	unsigned int i, j;
		
	for (i = 0; i <= n/2; i++) {
		j = v[n-i];
		v[n-i] = v[i];
		v[i] = j;	
	}
	return v;
}

unsigned int *read_file(char *nome, int *n) {
	FILE *file;
	unsigned int *v = NULL;

	file = fopen(nome, "r");
	
	do{
		if(!feof(file)){
			v = (unsigned int *)realloc(v, sizeof(int)*((*n)+1));
			fread((v+((*n)++)), sizeof(int), 1, file);	
		}
	}while (!feof(file));

	fclose (file);

	v = invert(v, *n);

	return v;
}

void mypow(int *j) {
	int i, k;
	
	k = *j;
	*j = 1;

	for(i = 0; i < k; i++)
		(*j) *= 10;	

	return ;
}

unsigned int *map (char *nome, unsigned int *v, int n){
	char c;
	int i = 0, j;

	c = (*nome);
	
	j = c - 48;
	
	while(v[i] == 0) i++;
	
	for ( ; i <= n; i++){
		if(j != 0){
			mypow(&j);	
			v[i] = (v[i] / j);
		}

		v[i] = v[i]%10;
		j = v[i];
	}
	return v;	
}
int trufal(char v){
	
		if ((v > 47 && v < 59) || (v > 64  && v < 91) || (v > 96 && v < 123) || v == ' ' || v == ',' || v == '.' || v == '(' || v == ')' || v == '!' || v == '?' || v == '\0')
			return 1;
		else 
			return 0;
}

unsigned int *shift(unsigned int *v, int n){
	int i;

	for (i = 0; i <= n; i++){
		if(trufal((char)v[i]) == 1)
			 v[i] = v[i];
	
		else
			v[i] = v[i] >> 1; 			
	}

	return v;
}

void printxt (char *v, int n) {
	int i;

	for (i = 0; i <= 4*n; i++)
		printf("%c", v[i]);

	return;
}

int repetem (char *v, char *key, int n){
	int i, j, k, rep = 0;
		
	i = strlen(key);

	for (j = 0; j <= (n-i); j++)
		for (k = 0; k <= i; k++)
			if(key[k] == v[j+k] && k == i)
				rep++;		
	return rep;
}

int main (int argc, char *argv[ ]){
	char *nome, *key;
	unsigned int *v, n = 0;
	int a;

	nome = read();

	v = read_file(nome, &n);

	scanf("%d", &a);	

//	printf("%s\n%d\n", nome, n);	
	
	if(a == 1){
		v = map(nome, v, n);
	while(v[a] == 0) a++;	
		for ( ; a <= n; a++) printf("%u", v[a]);	
	}

	else
	v = shift(v, n);
	
	if (a == 2)
		printxt((char*)v, n);	
	
	if (a == 3){fgetc(stdin);
		key = read();
		a = repetem ((char *)v, key, n);
		printf("%d", a);
	}

	free(nome);
	free(key);
	free(v);
	return 0;
}
