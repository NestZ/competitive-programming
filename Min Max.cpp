#include<stdio.h>

int main() {
	int n,i,r,max = 2000000000,min = -2000000000;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&r);
		
		
		if (r>min)
		{min=r;}
		
		if (r<max)
		{max=r;}
	}
	
	printf("%d\n%d",max,min);
	
}
