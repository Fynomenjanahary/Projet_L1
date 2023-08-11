#include <stdio.h>
#include <stdlib.h>
	
int main(){
	int i=0 , j=0;
	int h;
	printf("entrez la longueur du diagonal : ");
	scanf("%d",&h);
	for(i=0 ; i<=(h-2) ; i++){
		for(j=0 ; j<(h+2-i) ; j++)
			printf(" ");
		for(j=0 ; j<((2*i)-1) ; j++)
			printf("*");
		printf("\n");
	}
	
	for(i=0;i<h; i++){
		for(j=0;j<((2*i)-1);j--)
			printf(" ");
		for(j=(h-2);j>0;j-=2)
			printf("*");
		printf("\n");
	}
	
	return 0;
}

