#include <stdio.h>
#include <stdlib.h>
int longueur();
int** allouer(int n);
int** remplissage(int n , int **tab);
void affichage(int n , int** tab);

int main(){
	int n=0;
	printf("entrez le nombre qui détermine la dernière coefficient à afficher :");
	n = longueur();
	int **triangle = NULL;
	triangle = allouer(n);
	triangle = remplissage( n,triangle);
	affichage(n , triangle);
	
	free(triangle);
}
int longueur(){
	int n;
	scanf("%d",&n);
	return n;
}
int** allouer(int n){
	int ** tab=NULL;
	tab = malloc ((n+1)* sizeof(int *));
	for(int i=0; i<n+1 ; i++){
		tab[i] = malloc ((n+1)* sizeof(int));
	}
	return tab;
} 
int** remplissage(int n , int **tab){
	tab [0][0]=1;
	tab [1][0]=1;
	tab [1][1]=1;
	
	int i;
	int j;
	
	for(i=2 ; i<n+1 ; i++){
		for(j=0 ; j<n+1 ; j++){
			if (i==j){
				tab[i][j] =1;
			}
			if (j==0){
				tab[i][j] =1;
			}
			else{
				tab[i][j]=tab[i-1][j-1] + tab[i-1][j];
			}
		}	
	}
	return tab;
}
void affichage(int n , int** tab){
	for(int i=0 ; i<n+1 ; i++){
		for(int j=0 ; j<=i ;j++){
			printf("%d\t",tab[i][j]);
		}
		printf("\n");
	}
	
}
