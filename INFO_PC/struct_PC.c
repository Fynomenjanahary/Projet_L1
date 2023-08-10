#include <stdio.h>
#include <stdlib.h>
#define t 6
#include "struct_PC_Lib.h"

int main(){
	FILE *file;
	file = fopen("PC.csv","a+");
	if(file == NULL){printf("Erreur lors de l'ouverture\n");}
	Machine Pc[t];
	//fprintf(file,"Marque,Etiquette,Adresse MAC\n");
	for(int i=0 ; i<t ; i++){
		printf("Marque : "),scanf("%s",Pc[i].marque);
		printf("Etiquette : "),scanf("%s",Pc[i].etiquette);
		printf("Adresse MAC : "),scanf("%s",Pc[i].mac);
		fprintf(file,"%s,%s,%s\n",Pc[i].marque,Pc[i].etiquette,Pc[i].mac);
	}
	fclose(file);
	return 0;
}
