#include <stdio.h>

int a,b,c,x,y;

int main(){
	
	scanf("%d%d%d",&a,&b,&c);
	
	x = (c-b)-1;
	y = (b-a)-1;
	
	if(x>y){printf("%d",x);}
	else {printf("%d",y);}
	
	return 0;
}
