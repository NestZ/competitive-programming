#include <stdio.h>
int n[5];
int a,b;

int main(){
	scanf("%d",&n[0]);
	a = n[0]%3;
	b = n[0]%11;

	printf("%d %d",a,b);
	
	}
