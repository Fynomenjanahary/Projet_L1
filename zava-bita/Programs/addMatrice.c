#include<stdio.h>
#include<malloc.h>

/*int main(){
// entrée des données
	int tab1[10] [10];
	int tab2[10] [10];
	int addi[10] [10];
	int line,col;
	int i,j;
	
	printf("entrez le nombre de lines et de colonnes :\n");
	scanf("%d %d",&line ,&col);

	printf("les éléments da la première matrice\n");
	for(i=0;i<line;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d ",&tab1[i] [j]);
		}
		printf("\n");
	}
// Affichage de le première matrice
	for(i=0;i<line;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d  ",tab1[i] [j]);
		}
		printf("\n");
	}
	
	printf("les éléments da la deuxième matrice\n");
	for(i=0;i<line;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d ",&tab2[i] [j]);
		}
		printf("\n");
	}
// Affichage de le deuxième matrice
	for(i=0;i<line;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d  ",tab1[i] [j]);
		}
		printf("\n");
	}
// Calcul de la somme des deux matrices
	printf("\n");
	for(i=0;i<line;i++)
	{
		for(j=0;j<col;j++)
		{
			addi[i][j] = (tab1[i][j])+(tab2[i][j]);
			printf("%d ",addi[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/

int entrerNombre();
int* allouer(int taille);
void entrerValTab(int *tab , int taille);
void afficherTab(int *tab , int taille);

int main(){
	int taille;
	int *tab;
	
	taille=entrerNombre();
	tab=allouer(taille);
	entrerValTab(tab,taille);
	afficherTab(tab,taille);
	free(tab);
	
	return 0;
}

int entrerNombre(){
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
