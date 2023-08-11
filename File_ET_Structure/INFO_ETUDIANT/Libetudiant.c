#include "Libetudiant.h"

int count_line(int count , FILE *file){
	
	while (! feof (file)){
			if(fgetc(file) == '\n'){
				count++;
			}
	}
	
	return count;
}

char** SepareeMot(char*mot,char ch){
	char **MotSeparee=malloc(sizeof(char*)*10000);
	for(int i=0 ; i<10000 ; i++){
		MotSeparee[i] = malloc(sizeof(char)*30000);
	}
	int k=0,j=0;
	for(int i=0; i<strlen(mot); i++){
		if(mot[i]==ch){
			k++;j=0;
		}
		else {
			MotSeparee[k][j] = mot[i];
			j++;
		}
	}
	return MotSeparee;
}


Etudiant* taking(FILE* file , int count){
	char line[100000];
	char **str;
	char sep=',';
	Etudiant *Info = malloc(sizeof(Etudiant)*count);
	for(int i=0;fgets(line,100000,file) != NULL;i++){
		//printf("%s\n",line);
		//sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",Info[i].nom,Info[i].prenom,Info[i].tel,Info[i].mail,Info[i].adresse,Info[i].date,Info[i].lieu,Info[i].anne,Info[i].genre,Info[i].cin,Info[i].url);
		str = SepareeMot(line,sep);
		//printf("%s\n",str[0]);
		strcpy(Info[i].nom , str[0]);strcpy(Info[i].prenom , str[1]);strcpy(Info[i].tel , str[2]);strcpy(Info[i].mail , str[3]);strcpy(Info[i].adresse , str[4]);strcpy(Info[i].date , str[5]);strcpy(Info[i].lieu , str[6]);strcpy(Info[i].anne , str[7]);strcpy(Info[i].genre , str[8]);strcpy(Info[i].cin , str[9]);strcpy(Info[i].url , str[10]);
		
	}
	return Info;
}

Etudiant* triage(Etudiant* Info , int count){
	for(int i=1 ; i<count ; i++){
		for(int j=i+1 ; j<count ; j++){
			if(strcmp(Info[i].nom,Info[j].nom)>1){
				Etudiant tmp = Info[j];
				Info[j]=Info[i];
				Info[i]=tmp;
			}
		}
	}
	
	return Info;
}

FILE* submit(Etudiant* Info , int count){
	FILE* trie = fopen("/home/fifaliantsoa/info_trie2.csv","a+");
	
	for(int i=0;i<count;i++){
		fprintf(trie,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",Info[i].nom,Info[i].prenom,Info[i].tel,Info[i].mail,Info[i].adresse,Info[i].date,Info[i].lieu,Info[i].anne,Info[i].genre,Info[i].cin,Info[i].url);
	}
	
	
	return trie;
}
