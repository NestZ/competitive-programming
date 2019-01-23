#include <stdio.h>

int i=0,num[4],max,min;

int main(){
	
	while(i<4){scanf("%d",&num[i]);i++;}
	
	max,min = num[0];
	
	i = 0;
	
	while(i<3){
	if (num[i]>max){max=num[i];}
	i++;
	}
	
	i = 0;
	
	while(i<3){
	if (num[i]<min){min=num[i];}
	i++;
	}
	
	return 0;
}
