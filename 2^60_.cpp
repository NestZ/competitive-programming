#include <stdio.h>

long a[10000];
int i;

int main(){
	a[1]=2;
	for(i=0;i<59;i++){a[i]=a[i]*2;}
	printf("%d",a[i]);
	
	return 0;
}
