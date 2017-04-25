#include <stdlib.h>
#include <stdio.h>

char **create_hash ( ){			//cria o jogo da velha
	int i;
	char **hash;

	hash = (char **)malloc(3 * sizeof(char *));

	for (i = 0; i < 3; i++)
		hash[i] = (char *)calloc(3, sizeof(char));

	return hash;
}

int line(char **hash, int i){
	int j, sum = 0;

	for (j = 0; j < 3; j++)
		sum += hash[i][j];

	return sum;
}

int col (char **hash, int i){
	int j, sum = 0;

	for (j = 0; j < 3; j++)
		sum += hash[j][i];

	return sum;
}

int diag1 (char **hash){
	int i, sum = 0;

	for (i = 0; i < 3; i++)
		sum += hash[i][i];

	return sum;
}

int diag2 (char **hash){
	int i, sum = 0;

	for (i = 0; i < 3; i++)
		sum += hash[i][2-i];

	return sum;
}
	/*para saber quando o jogador conseguiu colocar 3 simbolos consecutivos
	usei a ideia de que a soma das linhas ou diagonais ou colunas teria que
	ser equivalente a 3xSimbolo 'O' = 79 ou 'X' = 88, por isso o 237 e 264*/

int win (char **hash, int *player) {
	int i;			
	
	*player = 3;
						//checagem reconfigurada
	for (i = 0; i < 3; i++) {
		if (line(hash, i) == 237 || col(hash, i) == 237 || diag1(hash) == 237 || diag2(hash) == 237){
			*player = 0;
			return 1;
		}
		else if (line(hash, i) == 264 || col(hash, i) == 264 || diag1(hash) == 264 || diag2(hash) == 264){
			*player = 1;
			return 1;
		}
	}

	return 0;
}

void tic_tac_toe (char **hash){		//'O' começa
	int i, j, k, p;
	
	for (k = 0; k < 10 && !win(hash, &p); k++){		//9 e o maior numero de jogadas (3x3)
		scanf("%d %d", &i, &j);				//for assim para retirar o 'break'
			if (k%2)	hash[i][j] = 'X';
			else 		hash[i][j] = 'O';
	}
	
	if (p != 3)
		printf("%d", p);
	else printf("empate");

	return;
}


int main (int argc, char *argv[ ]){
	char **hash;
	int i;

	hash = create_hash( );

	tic_tac_toe(hash);

	for (i = 0; i < 3; i++)
		free(hash[i]);

	free(hash);
	
	return 0;
}
