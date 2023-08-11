#include <stdio.h>
#include <stdlib.h>
#define t 2
#include "Libetudiant.h"

int main(){
	FILE *file;
	file = fopen("info_Etudiant.csv","a+");
	Etudiant Lmit[t];
	//fprintf(file,"Nom,Prenom,Date de naissance,Age,Adresse,Téléphone\n");
	for(int i=0 ; i<t ; i++){
		printf("Nom : "),scanf("%s",Lmit[i].nom);
		printf("Prenom : "),scanf("%s",Lmit[i].prenom);
		printf("Tel : "),scanf("%s",Lmit[i].tel);
		printf("Mail : "),scanf("%s",Lmit[i].mail);
		printf("Adresse : "),scanf("%s",Lmit[i].adresse);
		printf("Date de naissance : ");scanf("%s",Lmit[i].date);
		printf("lieu de naissance: "),scanf("%s",Lmit[i].lieu);
		printf("Année du Bacc : "),scanf("%s",Lmit[i].anne);
		printf("CIN : "),scanf("%s",Lmit[i].cin);
		printf("URL du compte Github: ");scanf("%s",Lmit[i].url);
		fprintf(file,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",Lmit[i].nom,Lmit[i].prenom,Lmit[i].tel,Lmit[i].mail,Lmit[i].adresse,Lmit[i].date,Lmit[i].lieu,Lmit[i].anne,Lmit[i].genre,Lmit[i].cin,Lmit[i].url);
	}
	fclose(file);
	return 0;
}
