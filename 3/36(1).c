#include<stdio.h>

int main(int argc, char * argv[]) {
    double n, soma, pow, k = 1, fat = 1, sign = 1;

    scanf("%lf", &n);
    soma = n;
    pow = n;

    while(k < 300) {
        pow *= n*n;
        sign *= -1;
        fat *= (2*k)*((2*k) + 1);
        soma += ((sign*pow)/fat);
        k++;
    }
    printf("%lf", soma);

    return 0;
}
