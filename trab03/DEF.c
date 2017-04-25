//EDSON YUDI TOMA 9791305
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *read() {	//Ler o nome do arquivo até o ENTER e adicionar um terminador '\0'
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

unsigned int *reverse(unsigned int *v, int n){ //>Reverter a ordem dos numeros
        unsigned int i, j;

        for (i = 0; i < n/2; i++) {	//>N numeros, troca-se o 0 com o N, 1 com N-1... 			|
                j = v[n-1-i];		//>Caso N impar troca-se a posicao ate (n/2 - 1) e (n/2) 		|==> Ha algum erro aqui!
                v[n-1-i] = v[i];		//>Caso N par troca-se a posicao ate (n/2) >> inverte com ele mesmo	|
                v[i] = j;
        }
        return v;
}

unsigned int *read_file(char *nome, int *n) {	//>Para ler o arquivo e armazenar os dados em um vetor na heap, é preciso o nome...
	FILE *file;				//... e o *n é somente para aramazenar o comprimento do vetor para uso nas outras funcoes
	unsigned int *vec;
	int len;	

	file = fopen(nome, "r");	//>Abertura

	fseek(file, 0, SEEK_END);	//>Posicionar o 'cursor' no final do arquivo
	len = ftell(file)/4;		//>Retornar o valor do comprimento do vetor pela posicao do 'cursor'(/4, pois um uns. int ocupa 4bytes)
	*n = len;			//>Armazenar na stack o comprimento para uso nas outras funcoes
	fseek(file, 0, SEEK_SET);	//>Retornar o cursor para o inicio do arquivo

	vec = (unsigned int *)calloc(len, sizeof(int));		//>Alocar, na heap, um vetor zerado para armazenar os dados do arquivo .bin
	fread(vec, 4, len, file);		//>Ler o binario (de uma vez) e armazenar no vetor (vetor, sizeof(int), comprimento, binario)

	vec = reverse(vec, len); 		//>Reverter o vetor
	
	fclose(file);				//>Fechamento

	return vec;		//>Retorno
}

void mypow(unsigned int i, int *j) {		//>A principio isso era uma alternativa a func. pow (math.h), mas ele foi alterado
        int k;

        for(k = 0; k < *j; k++)		//	Por exemplo tem-se como entrada o numero j = 0, de (0).bin
             i /= 10;			//		entao precisamos dessa funcao para saber quantas vezes o proximo numero
					//==>		sera dividido por 10, e depois retirar seu modulo...
	*j = (i%10);			//	Por exemplo o numero 2711 o digito da posicao 0 seria 1, por iso pega-se o resto	
					//		da divisao por 10. Mas agora caso fosse o 2 digito, teriamos q dividir
        return;				//		o 2711 por 10 uma vez antes de pegarmos o resto da divisao: 271.
}

void map (char *nome, unsigned int *vec, int n){	//>Com ajuda do 'mypow' imprimir na tela os valores da 1 parte do trab.
        char c;		
        int i , j;

        c = (*nome);		//>Para pegar o 1 caracter do nome do arquivo (x).bin

        j = c - '0';		//>Converter o (x) de um valor da ASCII para um valor int.

        for (i = 0; i < n; i++){		//
        	mypow(vec[i], &j);		//===>Imprimir os valores obtidos
			 printf("%d", j);	//
	}				
       
        return ;
}

int trufal(unsigned int vec){		//>Funcao para checar se o inteiro possui caracteres validos
	int i, j = 0;
	char *v = (char*)&vec;

	for (i = 0; i < 4; i++){
                if ((v[i] > 47 && v[i] < 59) || (v[i] > 64 && v[i] < 91) || (v[i] > 96 && v[i] < 123) || v[i] == ' ' || v[i] == ',' || v[i] == '.' || v[i] == '(' || v[i] == ')' || v[i] == '!' || v[i] == '?' || v[i] == '\0')
	    	  j++;	}	//	|
		  if(j == 4)	//	|Testes
	
		return 1;		//>Se todos os caracteres forem validos retorna 1
       	else
       	        return 0;	//>Caso contrario retorna 0
	}
//}

unsigned int *shift(unsigned int *v, int n){	//>Shiftar os valores
	int i;

	for (i = 0; i < n; i++){
		if(trufal(v[i]) == 1)	//>Caso o numero possua caracteres validos, nao ha  shift
			 v[i] = v[i];
	
		else
			v[i] = v[i] >> 1; 	//>Else, shift de 1 para a direita
	}

	return v;	//>Retorno
}

int repetem (char *v, char *key, int n){	//>Fazer a contagem de quantas vezes a chave se repete na msg
	int i, j, k, rep = 0;
	
	i = strlen(key);	//>Comprimento da chave
	
	for (j = 0; j <= n*4 + 1; j++){				//
		for (k = 0; k <= i && key[k] == v[k+j]; k++);	//==>Varrer comparando e incrementando 'rep' quando encontrar iguais
			if (k == i) rep++;			//
	}							
	return rep;
}

int main (int argc, char *argv[ ]){
        char *nome, *key;
        unsigned int *v, n = 0;
        int a;

        nome = read();		//>Armazenar o nome do arquivo

        v = read_file(nome, &n);	//>Abertura e armazenamento

        scanf("%d", &a);	//>Qual parte?

//      printf("%s\n%d\n", nome, n);    <<Usado em testes

        if(a == 1)
                map(nome, v, n);	//>Imprimir na tela o "codigo"

        else
        v = shift(v, n);		//>Shift dos numeros para uso nas proximas funcoes

        if (a == 2)
                printf("%s", (char*)v);	//>Imprimir o texto contido nos numeros
		
        if (a == 3){
		fgetc(stdin);		//>Pular o ENTER digitado depois do 'scanf'
                key = read();
		a = repetem((char *) v, key, n);	//>Fazer a contagem e retornar o valor de vezes que repetem
                printf("%d", a);		//>Imprimir na tela o numero de vezes que a 'key' se encontra no texto
		free(key);	//>Nao se esqueca de liberar a memoria!!
        }	//Nao dar free de key fora da condicao, pois nao haveria um 'local' para ser liberado

        free(v);	//>FREE
	free(nome);	//>FREE

        return 0;	//>That's all folks!
}

