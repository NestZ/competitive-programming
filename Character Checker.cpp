#include <stdio.h>
#include <ctype.h>
#include <string.h>

int u,l,m,i;
char ch[10000];

int main(){

	scanf("%s",ch);

	for(i=0;i<strlen(ch);i++){
		if(isupper(ch[i]))u=1;
		else if(islower(ch[i]))l=1;
	}

	if(u==1&&l==0)printf("All Capital Letter");
	else if(u==0&&l==1)printf("All Small Letter");
	else printf("Mix");

	return 0;
}
