#include <stdio.h>

int main (int argc, char *argv[ ]){
	int n, d, i = 0;

	scanf("%d %d", &n, &d);

	while (n >= d){
		n -= d;
		i++;
	}

	printf("%d\n%d", i, n);

	return 0;
}
