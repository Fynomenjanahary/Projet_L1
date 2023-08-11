#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libetudiant.h"

int main(){
	FILE *file;
	FILE *trie;
	int count=0;
	
	file = fopen("info_Etudiant.csv","r");
	trie = fopen("/home/fifaliantsoa/info_trie2.csv","w+");
	if(trie == NULL || file == NULL){printf("Erreur lors de l'ouverture\n");}
	
	count=count_line(count,file);
	printf("ito ny isa'ny line %d\n",count);
	
	rewind(file);
	
	Etudiant *Info;
	Info = malloc(sizeof(Etudiant)*count);
	Info = taking(file , count);
	Info = triage(Info , count);
	/*for(int i=0;i<43;i++){
		printf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",Info[i].nom,Info[i].prenom,Info[i].tel,Info[i].mail,Info[i].adresse,Info[i].date,Info[i].lieu,Info[i].anne,Info[i].genre,Info[i].cin,Info[i].url);
	}*/
	trie = submit( Info ,  count);
	fclose(file); 
	fclose(trie);
	
	return 0;
}

