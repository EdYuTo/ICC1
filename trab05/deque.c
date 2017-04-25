#include <stdlib.h>
#include <stdio.h>

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
	return deque->first->c;
}

/* Retorna o elemento armazenado atrás do Deque. */
char back(Deque *deque) {
	return deque->last->c;
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
	
	deque->size--; //decrementa o tamanho!
	
	deque->first = deque->first->next;
	free(deque->first->previous);
	deque->first->previous = NULL;
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

	deque->size--; //decrementa o tamanho!

	deque->last = deque->last->previous;
	free(deque->last->next);
	deque->last->next = NULL;	

	return;
}

/* Imprime todos os elementos armazenados no Deque. */
void print(Deque *deque) {
	
	if (deque->first == NULL)	return;
	
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

int main(int argc, char *argv[ ]) {
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
		printf("\n");

		deque->first = aux;
		
		destroy(deque);
	//observe que, como aux recebe um node de deque, ele e liberado junto com o deque
	}

	else if (opt == 2) {

	/*Devemos fazer algo para checar todas as combinacoes que seguem as regras da competicao,
		e terminar quando elas se esgotarem ou o resultado bater com a string resultado!

	REGRAS:
		-1 caracter e o do meio;
		-outros caracteres digitados serao colocados antes ou depois do meio.

	Assim, se dititarmos, por exemplo, ABC teriamos as possibiliades:
	
		ABC
		CAB
		BAC
		CBA

	Portanto teremos sempre 2^(n-1) combinacoes distintas, onde n corresponde ao numero de letras.

	*/
	}

	return 0;
}
