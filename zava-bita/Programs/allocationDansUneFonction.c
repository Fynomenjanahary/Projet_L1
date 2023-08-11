#include<stdio.h>
#include<stdlib.h>
/*
int entrerNombre();
int* allouer(int taille);
void entrerValTab(int *tab , int taille);
void afficherTab(int *tab , int taille);
*/
int entrerNombre();
int** allouer(int ligne , int col);
void entrerValTab(int **tab , int ligne , int col);
void afficherTab(int **tab , int ligne , int col);


int main(){
	//int taille;
	int ligne , col;
	int **tab;
	
	/*
	taille=entrerNombre();
	tab=allouer(taille);
	entrerValTab(tab,taille);
	afficherTab(tab,taille);
	*/
	
	ligne=entrerNombre();
	col=entrerNombre();
	tab=allouer(ligne , col);
	entrerValTab(tab , ligne , col);
	afficherTab(tab , ligne , col);
	free(tab);
	
	return 0;
}

/*int entrerNombre(){
	int n=0;
	printf("entrez la taille du tableau: ");
	scanf("%d",&n);
	
	return n;
}
int* allouer(int taille){
	int* qlq=NULL;
	qlq = (int*) malloc (sizeof(int)*taille);
	
	return qlq;
}
void entrerValTab(int *tab , int taille){
	for(int i=0 ; i<taille ; i++){
		scanf("%d",tab+i);
	}
}
void afficherTab(int *tab , int taille){
	printf("les elements du tableau sont:\n");
	for(int i=0 ; i<taille ; i++){
		printf("%d ",*(tab+i));
	}
}
*/

int entrerNombre(){
	int n;
	printf("entrez le nombre de lignes et de colonnes : ");
	scanf("%d",&n);
	
	return n;
}
int** allouer(int ligne , int col){
	int **qlq=NULL;
	qlq = (int**) malloc(ligne*sizeof(int*));
	for(int i=0 ; i<ligne ; i++){
		qlq[i] =  (int*)malloc( col * sizeof(int));
	}
	if(qlq==NULL){
		exit (1);
	}
	
	return qlq;
}
void entrerValTab(int **tab , int ligne , int col){
	for(int i=0 ; i<ligne ; i++){
		for(int j=0 ; j<col ; j++){
			scanf("%d",&tab[i][j]);
		}
	}
}
void afficherTab(int **qlq , int ligne , int col){
	printf("les elements du tableau sont:\n");
	for(int i=0 ; i<ligne ; i++){
		for(int j=0 ; j<col ; j++){
			printf("%d ",qlq[i][j]);
		}
		printf("\n");
	}
}
