#include <stdio.h>
#include <stdlib.h>

int longueur();
int** allouer(int n);
int** remplissage(int n , int** tab);

int main(){
	int haut;
	int bas;
	int** triangle=NULL;
	printf("NB: le nombre en haut doit etre plus grand ou égale au nombre en bas !!!\n");
	
	printf("entrez le premier nombre pour faire le combinaison :");
	haut=longueur();
	printf("entrez le deuxième nombre bas pour faire le combinaison :");
	bas=longueur();
	
	/*if(haut==0 || bas==0){
		printf("la combinaison de %d et %d est 1 \n",bas , haut);
	}
	*/
	if(haut>bas){
		int tmp;
		tmp=haut;
		haut=bas;
		bas=tmp;
	}
	
	triangle = allouer(bas);
	triangle = remplissage( bas,triangle);
	
	printf("la combinaison de %d et %d est %d \n",bas , haut ,triangle[bas][haut]);
	free(triangle);
	return 0;
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
