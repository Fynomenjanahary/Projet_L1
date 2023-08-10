#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char etiquette[300];
	int num;
	char marque[300];
	char mac[300];
}Trie;

int count_line(int count , FILE *file);
Trie* taking( FILE *file , int count);
Trie* triage(Trie* Line , int count);
FILE* submit(Trie* Info , int count);

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
	
	Trie *Line;
	Line = malloc(sizeof(Trie)*count);
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

int count_line(int count , FILE *file){
	
	while (! feof (file)){
			if(fgetc(file) == '\n'){
				count++;
			}
	}
	
	return count;
}

Trie* taking(FILE* file , int count){
	Trie *Line = malloc(sizeof(Trie)*count);
	char raiso[500];
	for(int i=0;fgets(raiso,500,file) != NULL;i++){
		sscanf(raiso,"%[^-]%d,%[^,],%[^\n]",(Line+i)->etiquette,&(Line+i)->num,(Line+i)->marque,(Line+i)->mac);
	}
	return Line;
}

Trie* triage(Trie* Line , int count){
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

FILE* submit(Trie* Line , int count){
	FILE* trie = fopen("PC_trie.csv","a+");
	
	for(int i=0;i<count;i++){
		fprintf(trie,"%s%d,%s,%s\n",(Line+i)->etiquette,(Line+i)->num,(Line+i)->marque,(Line+i)->mac);
	}
	
	
	return trie;
}
