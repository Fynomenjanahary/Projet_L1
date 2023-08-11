#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libpc.h"

int main(){
	FILE *file;
	FILE *trie;
	int count=0;
	
	file = fopen("PC.csv","r");
	trie = fopen("PC_trie.csv","a+");
	if(trie == NULL || file == NULL){printf("Erreur lors de l'ouverture\n");}
	
	count=count_line(count,file);
	printf("ito ny isa'ny line %d\n",count);
	
	rewind(file);
	
	Machine *Line;
	Line = malloc(sizeof(Machine)*count);
	Line = taking(file , count);
	Line = triage(Line , count);
	trie = submit(Line,count);
	
	for(int i=0;i<26;i++){
		printf("%s%d\n",(Line+i)->etiquette,Line[i].num);
	}
	
	fclose(file); 
	fclose(trie);
	
	return 0;
}

