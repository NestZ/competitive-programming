#include <stdio.h>
#include <math.h>

int r;
double pi = 4*atan(1),a,b;

int main(){

	scanf("%d",&r);

	a = r*r*pi;
	b = r*r*2;
	
	printf("%f\n",a);
	printf("%f",b);

	return 0;

}
