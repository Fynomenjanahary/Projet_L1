#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_Lib_Etudiant.h"

int main(){
	FILE *file;
	FILE *trie;
	int count=0;
	
	file = fopen("info_Etudiant.csv","r");
	trie = fopen("info_trie.csv","w+");
	if(trie == NULL || file == NULL){printf("Erreur lors de l'ouverture\n");}
	
	count=count_line(count,file);
	printf("ito ny isa'ny line %d\n",count);
	
	rewind(file);
	
	Etudiant *Info;
	Info = malloc(sizeof(Etudiant)*count);
	Info = taking(file , count);
	Info = triage(Info , count);
	
	for(int i=0;i<26;i++){
		printf("%s\n",Info[i].nom);
	}
	trie = submit( Info ,  count);
	fclose(file); 
	fclose(trie);
	
	return 0;
}

