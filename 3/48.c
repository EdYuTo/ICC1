#include <stdio.h>

int mmc (int i, int j, int k){

	if (i%k == 0 && j%k == 0)
		return k * mmc(i/k, j/k, k);

	else if (i%k != 0 && j%k == 0)	
		return k * mmc(i, j/k, k);

	else if (i%k == 0 && j%k != 0)
		return k * mmc(i/k, j, k);

	else if (i == 1 && j == 1) 
		return 1;

	else if (i%k != 0 && j%k != 0)
		return mmc(i, j, ++k);
}

int main (int argc, char *argv[ ]){
	int i, j, min, aux;

	scanf("%d %d", &i, &j);

	min = mmc(i, j, 2);
	
	printf("%d", min);
	
	return 0;
}
