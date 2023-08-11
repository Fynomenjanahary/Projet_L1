#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE *pfichier;	/* pointeur sur un fichier */
	char nomfichier[20], nompersonne[20];
	int i, nbrenregistrements;
	
/** creation et remplissage du fichier **/
	printf("quel est le nom du fichier à créer ?");
	scanf("%s",nomfichier);
	
/** w: write r: read a: append **/
	pfichier = fopen(nomfichier, "w");
	if(pfichier == NULL){
		printf("Erreur de creation du fichier \n");
		exit(-1);	/* Abandonner le programme */
	}
	
	printf("Nombre de personnes à stocker : ");
	scanf("%d",&nbrenregistrements);
	
	for(i = 0; i< nbrenregistrements; i++){
		printf("Entrez le nom de la personne :");
		scanf("%s",nompersonne);
		fprintf(pfichier, "%s\n", nompersonne);
	}
	fclose(pfichier);
	
/** Lecture et affichage du fichier **/
	pfichier = fopen(nomfichier, "r"); // read
	if(pfichier == NULL){
		printf("\aErreur d'ouverture du fichier \n");
		exit(-2);
	}
	
	while (! feof (pfichier)){
		fscanf(pfichier, "%s ", nompersonne);
		printf("Nom : %s\n", nompersonne);
	}
	fclose(pfichier);
	
	return 0;
}
