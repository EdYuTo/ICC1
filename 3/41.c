#include <stdlib.h>
#include <stdio.h>

int **create_month (int days){
	int **month, i;

	month = (int **)malloc(days * sizeof(int *));

	for (i = 0; i < days; i++){
		month[i] = (int *)malloc(2 * sizeof(int));
		month[i][0] = i + 1;
	}
	
	return month;
}

void sales (int **month, int days, int *max){	//max tem q ser = 0
	int i;

	for (i = 0; i < days; i++){
		scanf("%d", month[i]+1);	//evitar usar &m[i][1]
			if (month[i][1] > *max)
				*max = month[i][1];
	}
	return;
}

void print(int **month, int days, int max){
	int i, aux = 0;

	printf("%d\n", max);	

	for (i = 0; i < days; i++)
		if (month[i][1] == max)
			printf("%d\n", month[i][0]);

	return;
}

void freem (int **month, int days){
	int i;

	for (i = 0; i < days; i++)
		free(month[i]);

	free(month);

	return;
}

int main (int argc, char *argv[ ]){
	int **month, max = 0;

	month = create_month(31);

	sales(month, 31, &max);	

	print(month, 31, max);

	freem(month, 31);

	return 0;
}
