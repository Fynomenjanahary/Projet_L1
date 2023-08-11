#include <stdio.h>
#define taille 3
void init(int tab[5] [5]);
void affichage(int tab[5][5]);
int main(){

/// Data
	int tab [5][5]={{0},{0}};
/*	
/// Calculation	
	for(int i=0 ; i < 5 ; i++){
		for(int j=0 ; j< 5 ; j++){
		printf("tab[%d] [%d] =",i,j);
		scanf("%d",&tab[i][j]);
		}
	}
*/	
/// Result
/*
	for(int i=0 ; i<taille ; i++){
		for(int j=0 ; j<taille ; j++){
			printf("%d\t",tab[i] [j]);
		}
		printf("\n\n");
	}
*/
	affichage(tab);
	
	return 0;
}

void init(int tab[5] [5]){
	for(int i=0 ; i < 5 ; i++){
		for(int j=0 ; j< 5 ; j++){
		printf("tab[%d] [%d] =",i,j);
		scanf("%d",&tab[i][j]);
		}
	}

}

void affichage(int tab[5][5]){
	init(tab);
	printf("Les tableaux à deux dimension: \n");
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
}
