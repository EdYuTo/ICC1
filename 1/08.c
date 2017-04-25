#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int a, b, c;

   scanf("%d", &a);
   scanf("%d", &b);
   scanf("%d", &c);

   if((a*a==b*b+c*c)^(b*b==c*c+a*a)^(c*c==b*b+a*a)) {
    printf("SIM");
   }
   else {
    printf("NAO");
   }
   return 0;
}
