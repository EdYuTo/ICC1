#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){
    double a, b, c;
    char op;

    scanf("%lf", &a);
    scanf("\n%c", &op);
    scanf("%lf", &b);

    switch (op) {
        case '+':
            c = a + b;
            printf("%f", c);
            break;

        case '-':
            c = a - b;
            printf("%f", c);
            break;

        case '*':
            c = a * b;
            printf("%f", c);
            break;

        case '/':
            c = a / b;
            printf("%f", c);
            break;
        case '%':
            c = (a/b) * 100;
            printf("%f", c);
            break;
}
    return 0;
}
