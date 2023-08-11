#include "Libpc.h"

int count_line(int count , FILE *file){
	
	while (! feof (file)){
			if(fgetc(file) == '\n'){
				count++;
			}
	}
	
	return count;
}

Machine* taking(FILE* file , int count){
	Machine *Line = malloc(sizeof(Machine)*count);
	char raiso[500];
	for(int i=0;fgets(raiso,500,file) != NULL;i++){
		sscanf(raiso,"%[^-]%d,%[^,],%[^\n]",Line[i].etiquette,&Line[i].num,Line[i].marque,Line[i].mac);
	}
	return Line;
}

Machine* triage(Machine* Line , int count){
	for(int i=0 ; i<count ; i++){
		for(int j=i+1 ; j<count ; j++){
			if(Line[i].num<Line[j].num){
				int tmp;char temp[50];
				tmp = Line[j].num;
				Line[j].num = Line[i].num;
				Line[i].num = tmp;
				strcpy(temp , Line[j].etiquette);strcpy(Line[j].etiquette , Line[i].etiquette);strcpy(Line[i].etiquette , temp);
				strcpy(temp , Line[j].marque);strcpy(Line[j].marque , Line[i].marque);strcpy(Line[i].marque , temp);
				strcpy(temp , Line[j].mac);strcpy(Line[j].mac , Line[i].mac);strcpy(Line[i].mac , temp);
			}
		}
	}
	
	return Line;
}

FILE* submit(Machine* Line , int count){
	FILE* trie = fopen("PC_trie.csv","a+");
	
	for(int i=0;i<count;i++){
		fprintf(trie,"%s%d,%s,%s\n",(Line+i)->etiquette,(Line+i)->num,(Line+i)->marque,(Line+i)->mac);
	}
	
	
	return trie;
}
