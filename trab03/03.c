#include <stdlib.h>
#include <stdio.h>

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

char *shift(char *v, int n){
	int i;

	for (i = 0; i <= n*4; i++){
		if ((v[i] > 47 && v[i] < 59) || (v[i] > 64  && v[i] < 91) || (v[i] > 96 && v[i] < 123) || v[i] == ' ' || v[i] == ',' || v[i] == '.' || v[i] == '(' || v[i] == ')' || v[i] == '!' || v[i] == '?' || v[i] == '\0');
	
		else v[i] = v[i] >> 1;
	printf("%c ", v[i]);				 
	}
	return v;
}

int main (int argc, char *argv[ ]){
	char *nome;
	unsigned int *v, n = 0;
	int a;

	nome = read();

	v = read_file(nome, &n);

	scanf("%d", &a);	

//	printf("%s\n%d\n", nome, n);	
	
	if(a == 1)
	v = map(nome, v, n);	
	
	if(a==2)
	v = (unsigned int *) shift((char *) v, n);
	

	for (a = 0; a <= n; a++) printf("%u\n", v[a]);	
	
	free(nome);
	free(v);
	return 0;
}
