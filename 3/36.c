#include <stdio.h>

int main (int argc, char *argv[ ]){
	int i;
	double n, sin, fat = 1, pow;

	scanf("%lf", &n);

	sin = n;
	pow = n;

	for (i = 1; i < 300; i++){
		fat *= 2*i*(2*i+1);
		pow *= n*n; 		
			
		if(!(i%2))
			sin += pow/fat;
		if(i%2)
			sin -= pow/fat;
	}

	printf("%lf", sin);

	return 0;
}
