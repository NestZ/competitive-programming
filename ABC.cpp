#include<stdio.h>
#include <math.h>

int main() {
    int min,max,num1,num2,num3,a,b,c,i;
    char x[3];
    
		scanf("%d%d%d",&num1,&num2,&num3);
		scanf("%s",x);
		
		max=num1;
		min=num1;
		
		if (num2>max)
		{max=num2;}
		
		else if (num2<min)
		{min=num2;}
		
		
		if (num3>max)
		{max=num3;}
		
		else if (num3<min)
		{min=num3;}
		
		
		
		if (num1!=max&&num1!=min)
		{b=num1;}
		
		else if (num2!=max&&num2!=min)
		{b=num2;}
		
		else if (num3!=max&&num3!=min)
		{b=num3;}
		
		
		if (num1==max)
		{c=num1;}
		
		else if (num2==max)
		{c=num2;}
		
		else if (num3==max)
		{c=num3;}
		
		
		if (num1==min)
		{a=num1;}
		
		else if (num2==min)
		{a=num2;}
		
		else if (num3==min)
		{a=num3;}
		

		
		for(i=0;i<3;i++){
			if(x[i]=='A'){printf("%d ",a);}
			if(x[i]=='B'){printf("%d ",b);}
			if(x[i]=='C'){printf("%d ",c);}	
		}
		
	return 0;
}
