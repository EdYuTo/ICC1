#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *read( ){
	char c, *n = NULL;
	int i = 0;

	do {
		c= fgetc(stdin);
		n = (char *)realloc(n, 1*(i+1));
		n[i++] = c;
	}while (c != 10);
	
	n[--i] = '\0';
	
	return n;
}
int compare (char *n1, char *n2){
	int len1, len2, i, j;

	len1 = strlen(n1);
	len2 = strlen(n2);

	for (i = 0; i <= len1 - len2; i++){
		for (j = 0; j < len2 && n2[j] == n1[i+j]; j++); 
		if(j == len2)	return 1;
	}
	return 0;
}
void ifs_elses (char *n1, char *n2){
	int i, j;

	if (compare(n1, n2))
		printf("%s %s SIM", n2, n1);
	else if (compare(n2, n1))
		printf("%s %s SIM", n1, n2);
	else{
		i = atoi(n1);
		j = atoi(n2);
		
		if(i > j)
		printf("%d %d NAO", j, i);
		else
		printf("%d %d NAO", i, j);
	}

	return;
}
int main (int argc, char *argv[ ]){
	char *n1, *n2;	
	
	n1 = read( );
	n2 = read( );

	ifs_elses (n1, n2);
	
	free(n1);
	free(n2);

	return 0;
}
