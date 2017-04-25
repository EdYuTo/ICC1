#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read (char lim){
	int i = 0;
	char c, *text = NULL;

	do{
		c = fgetc(stdin);
		text = (char *)realloc(text, sizeof(char) * (i+1));
		if (c != 10)
			text[i++] = c;

	} while (c != lim);
	
	text = (char *)realloc(text, sizeof(char) * (i+1));
	text[i] = '\0';

	return text;
}

void order (char *text){
	char c;
	int i, j, len;
	
	len = strlen(text);
	
	for(i = 0; i < len-1; i++)
		for (j = i; j < len; j++)
			if (text[i] > text[j]){
				c = text[i];
				text[i] = text[j];
				text[j] = c;
			}
	return;
}

void print (int *text, int len){
	int i;

	for (i = 0; i < len/4; i++)
		printf("%d\n", text[i]);

	return;
}

int main (int argc, char *argv[ ]){
	char *text;
	int len;

	text = read('x');
	order(text);
	len = strlen(text);	
	print((int *)text, len);

	free(text);
	
	return 0;
}
