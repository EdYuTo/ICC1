#include <stdlib.h>
#include <stdio.h>


char *rname () {
	char c, *nome =NULL;
	int i = 0;

	do {
		c = fgetc(stdin);
		nome = (char *)realloc (nome, sizeof (char) * (i+1));
		nome[i++] = c;

	}while (c != 10);

	nome[--i] = '\0';	

	return nome;
}

unsigned int *rbin (char *nome, int *size) {
	FILE *file;
	int i = 0;
	unsigned int *vector = NULL, j;

	file = fopen(nome, "r");

	do{
		if(!feof(file)){
			fread (&j, sizeof(int), 1, file);
			vector = (unsigned int *)realloc(vector, sizeof(int) * (i+1));
			vector[i++] = j;	
		}
	}while (!feof(file));

	*size = i;		

	fclose(file);	

	return vector;
}

unsigned int *reverse (unsigned int *vec, int size){
	unsigned int i, j;

        for (i = 0; i <= size/2; i++) {
                j = vec[size-i];
                vec[size-i] = vec[i];
                vec[i] = j;
        }

	return vec;
}
 
void mypow(int *j) {
        int i, k;

        k = *j;
        *j = 1;

        for(i = 0; i < k; i++)
                (*j) *= 10;

        return ;
}

unsigned int *map (char *nome, unsigned int *vec, int size){
        char c;
        int i = 0, j;

        c = (*nome);

        j = c - 48;

        while(vec[i] == 0) i++;

        for ( ; i <= size; i++){
                mypow(&j);
                vec[i] = (vec[i] / j) % 10;
               // vec[i] = vec[i]%10;
                j = vec[i];
        }
        return vec;
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
	int size, part;
	unsigned int *vec;
	
	nome = rname();

	scanf("%d", &part);
	
	vec = rbin(nome, &size);
	
	vec = reverse(vec, size);

	if (part == 1){
		vec = map(nome, vec, size);
		
		for (part = 0; part <= size; part++)
			printf("%d", vec[part]);		
	}

	if (part == 2){
		vec = (unsigned int *)shift((char *)vec, size);

		for (part = 0, (char *) vec; part <= size*4; part++)
			printf("%c", vec[part]);
	}
	
	if (part == 3) {

	}
	
	free(nome);
	free(vec);

	return 0;
}
