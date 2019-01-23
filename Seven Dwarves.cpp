#include <stdio.h>

int num[9],E=0,ans,i,q=0,a=0,b=0,n,r,e;

int main(){
	
	while(q<9){scanf("%d",&num[q]);q++;}
	
	for(i=0;i<9;i++){
		
		E = E + num[i];
	}
	
	ans = E - 100;
	
	for(n=0;n<8;n++){
		r=n+1;
		while(r<9){
		
				if (num[n]+num[r]==ans){a=num[n];b=num[r];}
				else{}
				r++;
		}
		
	}
	
	for(e=0;e<9;e++){
		
		if(num[e]!=a&&num[e]!=b){printf("%d\n",num[e]);}
		
	}
	
	return 0;
}
