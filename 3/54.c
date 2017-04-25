#include <stdlib.h>
#include <stdio.h>

float calc (float a, float b, char op){
	float result;

	switch (op){
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '/':
			result = a / b;
			break;
		case '*':
			result = a * b;
			break;
	}
	return result;
}
char opinverter (char op){

	if (op == '+')
		return '-';

	else if (op == '-')
		return '+';

	else if (op == '*')
		return '/';

	else if (op == '/')
		return '*';

}
int main (int argc, char *argv[ ]){
	int i = 0;
	float a, b;
	char op;


	scanf("%f %f %c", &a, &b, &op);

	a = calc(a, b, op);

	while (!feof(stdin)){
		if(!feof(stdin)){
			i++;
			scanf("%f %c", &b, &op);
			a = calc(a, b, op);	
		}
	}
	if (i != 1){			//
		op = opinverter(op);	//
		a = calc(b, a, op);	//
	}				//
	else{				//-----> Gambiarra porque o !feof nao esta parando onde deveria...
		op = opinverter(op);	//
		a = calc(a, b, op);	//
	}				//
	printf("%f\n", a);		//

	return 0;
}
