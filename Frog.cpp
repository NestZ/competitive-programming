#include <stdio.h>

int a,b,i=1,n=0;

int main(){

	scanf("%d%d",&a,&b);

	if(a>b){printf("2");}
	
	else{while(n<b){n=a*i;i++;}printf("%d",i-1);}

	return 0;
}
