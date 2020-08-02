#include <stdio.h>

long m,n,i,j;

int main(){
	
	scanf("%d %d",&m,&n);
	
	
	int matrix[m][n],matrix2[m][n];
	
		
	for(j=0;j<m;j++){
		for(i=0;i<n;i++){
			scanf("%d",&matrix[j][i]);
		}
	}
	
	for(j=0;j<m;j++){
		for(i=0;i<n;i++){
			scanf("%d",&matrix2[j][i]);
		}
	}
	
	for(j=0;j<m;j++,printf("\n")){
		for(i=0;i<n;i++){
			printf("%d ",matrix2[j][i]+matrix[j][i]);
		}
	}
	
	return 0;
}
