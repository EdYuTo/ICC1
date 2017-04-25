#include <stdio.h>

float lucas (int i){

	if (i == 0)
		return 2;
	if (i == 1)
		return 1;

	return lucas(i-2) + lucas(i-1);
}

int main (int argc, char *argv[ ]){
	int i;

	scanf("%d", &i);

	printf("%f", lucas(i));	

	return 0;
}
