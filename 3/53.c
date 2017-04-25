#include <stdlib.h>
#include <stdio.h>

struct pais{
	char nome[3];		//usei vetor porque fiquei com duvidas de como usar ponteiro em structs...
	int ouro, prata, bronze;

};

void check (struct pais *dados, int n){
	int i, j;
	struct pais aux;

	for (i = 0; i < n - 1; i++)
		for (j = 0 + i; j < n; j++){
			if (dados[j].ouro > dados[i].ouro){
				aux = dados[i];
				dados[i] =  dados[j];
				dados[j] = aux;
			}

			else if (dados[j].prata > dados[i].prata 
				&& dados[j].ouro == dados[i].ouro){
	
				aux = dados[i];
				dados[i] =  dados[j];
				dados[j] = aux;
			}

			else if (dados[j].bronze > dados[i].bronze
				&& dados[j].prata == dados[i].prata 
				&& dados[j].ouro == dados[i].ouro){

				aux = dados[i];
				dados[i] =  dados[j];
				dados[j] = aux;
			}
		}
	return;				
}

int main (int argc, char *argv[ ]){
	int n, i;
	struct pais *dados;

	scanf("%d", &n);

	dados = (struct pais *)malloc(n * sizeof(struct pais));

	for (i = 0; i < n; i++){
		scanf("%s", dados[i].nome);
		scanf("%d %d %d", &dados[i].ouro, &dados[i].prata, &dados[i].bronze);
	}

	check(dados, n);

	for(i = 0; i < n; i++)
		printf("%s %d %d %d\n", dados[i].nome, dados[i].ouro, dados[i].prata, dados[i].bronze);

	free(dados);
			
	return 0;
}
