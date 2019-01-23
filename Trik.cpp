#include<stdio.h>
	
int i,pos1 = 1,pos2 = 0,pos3= 0;
char trik[50];

int main(){
	
	scanf("%s",&trik);
	
	for(i=0;i<49;i++)
	{
		if(trik[i]=='A')
		{
		
			if(pos1==1)
			{	
				pos1 = 0;
				pos2 = 1;	
			}
			
			else if(pos2==1)
			{
				pos1 = 1;
				pos2 = 0;		
			}
		
		}
		
		
		else if(trik[i]=='B')
		{
		
			if(pos2==1)
			{
				pos2 = 0;
				pos3 = 1;	
			}
			
			else if(pos3==1)
			{
				pos2 = 1;
				pos3 = 0;	
			}
		
		}
		
		
		else if(trik[i]=='C')
		{
		
			if(pos1==1)
			{
				pos1 = 0;
				pos3 = 1;
			}
			
			else if(pos3==1)
			{
				pos1 = 1;
				pos3 = 0;	
			}
		
		}	
		
	}

		if(pos1==1)
		{
			printf("1");
		}
		
		else if(pos2==1)
		{
			printf("2");
		}
		
		else if(pos3==1)
		{
			printf("3");
		}	
}
