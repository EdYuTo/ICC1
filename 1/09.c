#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

int a, i;
scanf("%d",&a);

int v[a];

for (i = 0; i < a; i++) {
        scanf("%d", &v[i]);}

int max, min;

max = min = v[0];

for(i = 0; i<a; i++) {
if(max<v[i]){ max = v[i];}
if(min>v[i]){ min = v[i];}}
printf("max: %d\nmin: %d", max, min);

return 0;
}

