#include <stdlib.h>
#include <stdio.h>

/*
1 ->N questoes
2 ->N alunos
3 ->Gabarito
4 ->Respostas
*/

char *get_gab (int n){
	char *gabarito;
	int i;

	gabarito = (char *)malloc(n*sizeof(char));

	for (i = 0; i < n; i++)
		scanf("\n%c", gabarito+i);	//Endereço inicial+i elementos --> nao ha necessidade de usar &	

	return gabarito;		
}

void get_note (int quest, int alu, char *gabarito){
	char resposta;
	int i, j;
	float valor, *nota;

	valor = 10.0 / quest;

	nota = (float *)calloc(alu, sizeof(float));	

	for (i = 0; i < alu; i++)
		for (j = 0; j < quest; j++){
			scanf("\n%c", &resposta);	//-\n->pular o enter
			if (resposta == gabarito[j])	
				nota[i] += valor;	
		}
	
	for (i = 0; i < alu; i++)
		printf("%.2f\n", nota[i]);

	free(nota);
	return;
}

int main (int argc, char *argv[ ]){
	char *gabarito;
	int nq, na;
	
	scanf("%d %d", &nq, &na);
			
	gabarito = get_gab(nq);
		
	get_note(nq, na, gabarito);

	free(gabarito);

	return 0;
}
