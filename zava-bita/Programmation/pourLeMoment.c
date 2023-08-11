#include<stdio.h>
void result(int n , int *scarre , int *scube);
int main(){
	printf("ceci est un programme pour calculer la somme des carrés et des cubes des n premiers entiers non nuls\n");

/// Données
	int n=3;			// Limite de la somme
	int scarre = 0,		// Somme des carrés à calculer
		scube = 0;		// Somme des cubes à calculer
/// Calcul
	printf("le nombre n=");
	scanf("%d",&n);
	result(n , &scarre , &scube);
/// Sortie
	printf("la somme des carres de %d premiers  entiers est %d\n",n , scarre);
	printf("la somme des cubes de %d premiers  entiers est %d\n",n , scube);
	return 0;
}
void result(int n , int *scarre , int *scube){
	*scarre = 0;
	*scube = 0;
	for(int i=1 ; i<=n ; i++){
		*scarre += (i*i);
		*scube += (i*i*i);
		}
}
