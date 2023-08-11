#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int random_int();
char *random_mot(int n);

int main(){
	//char *mot = (char*)malloc(100);
	printf("Le  mot random est  : %s", random_mot(random_int()));
	
}

int random_int(){
	int entier=0;
	FILE *pendu = fopen("pendu.txt", "r");
	if(pendu != NULL){
		while (! feof (pendu)){
			if(fgetc(pendu) == '\n'){
				entier++;
			}
		}
	}
	srand(time(NULL));
	entier =  rand() % ((entier-1) + 1);
	return entier;
}

char* random_mot(int n){
	char *mot = (char*)malloc(100);
	FILE *pendu = fopen("pendu.txt", "r");
	if(pendu != NULL){
		while(n != 0){
			if(fgetc(pendu) == '\n'){
				n--;
			}
		}
		fgets(mot, 100, pendu);
		mot[strlen(mot)] = '\n';
	}
	
	return mot;	
}
