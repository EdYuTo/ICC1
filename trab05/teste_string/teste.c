#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ENTER 10

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

void invert (char *text) {
	char aux;
	int i, size = strlen(text);

	for (i = 0; i < size/2; i++) {
		aux = text[i];
		text[i] = text[size-i-1]; //-1 pula o /0
		text[size-1-i] = aux;
	}

	return;
}
int aux_istrue (char *txt, char *chk, int starttxt, int *startchk, int *end) {

	if (txt[starttxt+1] == chk[*end-1]) {
		(*end)--;
		return 1;
	}
	else if (txt[starttxt+1] == chk[*startchk+1]) {
		(*startchk)++;
		return 1;
	}
	else
		return 0;
}

int istrue (char *txt, char *chk) {
	int starttxt = 0;
	int startchk = 0, end = strlen(txt) - 1;
	
	do {
		if (chk[startchk] == chk[end]) {
			if (aux_istrue(txt, chk, starttxt, &startchk, &end))
				continue; 
			else
				return 0;
		}
		else if (txt[starttxt] == chk[startchk])
			startchk++;
		else if (txt[starttxt] == chk[end])
			end--;
		
		else
			return 0;			
		starttxt++;

	} while (starttxt != strlen(txt)-1);

	return 1;
}

int main (int argc, char *argv[ ]) {
	char *txt, *chk;

	txt = readLine();
	invert(txt);

	chk = readLine();
	
	if (istrue(txt, chk)) 
		printf("S\n");
	else
		printf("N\n");

	free(txt);
	free(chk);

	return 0;
}
