#include <stdio.h>

int mdc (int i, int j, int k){
	
	if (i%k == 0 && j%k == 0)
		return k * mdc(i/k, j/k, k);

	else if (k <= i && k <= j)
		return mdc(i, j, ++k);

	else 
		return 1;
}

int main (int argc, char *argv[ ]){
	int i, j, max;

	scanf("%d %d", &i, &j);

	max = mdc(i, j, 2);

	printf("%d", max);

	return 0;
}
