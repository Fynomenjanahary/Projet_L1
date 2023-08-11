#include <stdio.h>
#include <stdlib.h>
#define tailleSousM 7
#define tailleSurM 9

/**********PROTOTYPES***********/

void init(int matrice [][tailleSurM]);
int nombreVoisin (int matrice [][tailleSurM] , int line , int col);
void miseAjour(int matrice [][tailleSurM]);
void afficheMatrice(int matrice [][tailleSurM]);
void line(int largeur);

/******************************/

int main(){
	int i;
	int nbrCycles;
	int matrice [tailleSurM][tailleSurM];
	char s[2];
	
	printf("Nombres de cycles : ");
	scanf("%i",&nbrCycles);
	
	init(matrice);
	printf("La population au depart : \n");
	afficheMatrice(matrice);
	printf("Pressez sur ENTER pour continuer!!!\n");
	gets(s);
	
	for(i=0 ; i<nbrCycles ; i++){
		miseAjour(matrice);
		printf("la population apres %d cycles : \n",i+1);
		afficheMatrice(matrice);
		printf("Pressez sur ENTER pour continuer!!!\n");
		gets(s);
	}

	return 0;
}

/********************INITIALISATION DE LA MATRICE**********************/
void init(int matrice [][tailleSurM]){
	int i,j;
	
	for(i=0 ; i<tailleSurM ; i++){
		for(j=0 ; j<tailleSurM ; j++){
			if(i<=j && )
	
	
	
}
