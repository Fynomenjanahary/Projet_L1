#include<stdio.h>
int main(){
	int n,max=0;
	do{
		printf("entrez n=");
		scanf("%d",&n);
	
	if(max<n){
		max=n;
	}
	}
	while(n!=0);
		printf("\n%d est le plus grand nombre de tous\n",max);
}
