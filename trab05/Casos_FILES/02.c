#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ENTER 10

/* Estrutura que armazena um elemento do Deque. */
typedef struct Node Node;

struct Node {
	char c;
	Node *previous;
	Node *next;
};


/* Estrutura que armazena o Deque completo (referência para os Nodes encadeados). */
typedef struct Deque Deque;

struct Deque { 
	Node *first;
	Node *last;
	int size;
};

/* Aloca um Deque vazio na Heap. */
Deque *create ( ) {
	Deque *deque;
	
	deque = (Deque *)malloc(sizeof(Deque));
	
	deque->first = NULL;
	deque->last = NULL;
	deque->size = 0;

	return deque;
}

/* Remove todos os elementos do Deque. */
void clear (Deque *deque) {
	Node *aux = deque->first;
	
	if (aux == NULL) return;	

//começa pelo 1 node e vai dando free ate chegar no ultimo...
	while (aux->next != NULL) {
		aux = aux->next;
		free(aux->previous);
	}

	free(deque->last);	

	return;
}

/* Remove todos os elementos e desaloca o Deque. */
void destroy (Deque *deque) {
	
	clear(deque);
	
	free(deque);

	return;
}

/* Insere um elemento na frente (na cabeça) do Deque. */
void push_front (Deque *deque, char c) {
	Node *n = malloc(sizeof(Node));
	
	deque->size++; //incrementa o tamanho!	

	n->c = c;
	n->next = deque->first;
	n->previous = NULL;
	if (deque->last == NULL) //se for igual a null, nao existe final e, portanto, nao existe lista!
		deque->first = deque->last = n;
	else {
		deque->first->previous = n;
		deque->first = n;
	}
	return;
}

/* Insere um elemento atrás (na cauda) do Deque. */
void push_back (Deque *deque, char c) {
	Node *n = malloc(sizeof(Node));

	deque->size++; //incrementa o tamanho!

	n->c = c;
	n->previous = deque->last;
	n->next = NULL;
	if (deque->first == NULL) //se for igual a null, nao existe comeco e, portanto, nao existe lista!
		deque->last = deque->first = n;
	else {
		deque->last->next = n;
		deque->last = n;
	}
	return;
//e o oposto do push_front em tudo...
}

/* Retorna o elemento armazenado na frente do Deque. */
char front(Deque *deque) {
	if (deque->first != NULL)
		return deque->first->c;
	else
		return 0;	//indica vazio
}

/* Retorna o elemento armazenado atrás do Deque. */
char back(Deque *deque) {
	if (deque->last != NULL)
		return deque->last->c;
	else
		return 0;	//indica vazio
}

/* Retorna a quantidade de elementos do Deque. */
int size(Deque *deque) {
	return deque->size;	
}

/* Retorna 1 caso o Deque esteja vazio e 0 caso contrário. */
int empty(Deque *deque) {
	return deque->first == NULL && deque->last == NULL ? 1 : 0;
}

/* Remove o elemento da frente do Deque. */
void pop_front(Deque *deque) {
	
	if (!empty(deque)) {
		deque->size--; //decrementa o tamanho!
		deque->first = deque->first->next;
			if (deque->first != NULL) {	
				free(deque->first->previous);
				deque->first->previous = NULL;
			}
	}
/*
	-----    -----
	| 1 | -> | 2 |  
	-----    -----

	1 recebe o proximo, ha liberacao do anterior
	e o proximo para de apontar para 1, passando
	a apontar para NULL	
*/
	return;
}

/* Remove o elemento de trás do Deque. */
void pop_back(Deque *deque) {

	if (!empty(deque)) {
		deque->size--; //decrementa o tamanho!
		deque->last = deque->last->previous;
			if (deque->last != NULL) {
				free(deque->last->next);
				deque->last->next = NULL;
			}
	}

	return;
}

/* Imprime todos os elementos armazenados no Deque. */
void print(Deque *deque) {
	
	if (deque->first == NULL) {
		printf("\n");
		return;
	}
	printf("%c", deque->first->c);	

	deque->first = deque->first->next;
	
	print(deque);
}

void dequeRead (Deque *deque) {
	char c;

	c = fgetc(stdin);

	if (c != ENTER)
		push_front(deque, c); //colocar o c no meio...

	do {
		c = fgetc(stdin);
			if (c != ENTER) {
				if (c >= deque->first->c)
					push_front(deque, c);
				else 
					push_back(deque, c);
			}
	} while (c != ENTER);
}

char *readLine ( ) {
        char c, *text = NULL;
        int i = 0;

        do {
                c = fgetc(stdin);
                text = (char *)realloc(text, sizeof(char) * (i+1));
                text[i++] = c;

        } while (c != ENTER);

        text[--i] = '\0';

        return text;
}

int checkDeque (Deque *deque, char *in, char *out) {
	int i;
	int start = 0, end = strlen(in) - 1;

	for (i = 0; i < strlen(out); i++)
		push_back(deque, out[i]);

	while (!empty(deque)) {
		if (front(deque) == back(deque) && deque->last->previous != NULL && deque->first->next != NULL) {
			if (in[end-1] == deque->last->previous->c || in[start] == deque->last->previous->c) {
				pop_back(deque);
				end--;
			}
			else if (in[start+1] == deque->first->next->c || in[end] == deque->first->next->c) {
				pop_front(deque);
				start++;
			}
			else
				return 0;
		}
		else if (in[start] == front(deque)) {
			start++;
			pop_front(deque);
		}
		else if (in[start] == back(deque)) {
			start++;
			pop_back(deque);
		}
		else if (in[end] == front(deque)) {
			end--;
			pop_front(deque);
		}
		else if (in[end] == back(deque)) {
			end--;
			pop_back(deque);
		}
		else
			return 0;
	}

	return 1;
}


int main(int argc, char *argv[ ]) {
	char *in, *out;
	int opt;
	Deque *deque;
	Node *aux;

	scanf("%d", &opt);
	fgetc(stdin); //pular um enter	

	if (opt == 1) {
		deque = create( );
		
		dequeRead(deque);

		aux = deque->first; 
	//criei um auxiliar porque a funçao recursiva muda o deque->first

		print(deque);

		deque->first = aux;
		
		destroy(deque);
	//observe que, como aux recebe um node de deque, ele e liberado junto com o deque
	}

	else if (opt == 2) {
		in = readLine( );
		out = readLine( );
		
		deque = create( );

		if(checkDeque(deque, in, out))
			printf("S\n");
		else
			printf("N\n");

		destroy(deque);
		free(in);
		free(out);
	}

	return 0;
}
/*observacao: nas linhas 92 e 74 poderia utilizar a funcao empty para checar se o deque estava vazio
mas como ela esta depois (e nao sabia se podia mudar a ordem das funçoes predefinidas), nao a utilizei...
*/
