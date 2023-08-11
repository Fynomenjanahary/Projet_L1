#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int random_int();
char *random_mot(int n);
int compteur(char* tab);
char* kernel(char* tab);

int main(){
	char* originalword;
	originalword = malloc (20);
	printf("Bienvenu  dans Mon Pendu !!!!!!!!!!!!\n");
	originalword = random_mot(random_int());
	originalword = kernel(originalword);
	
	return 0;
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

char *random_mot(int n){
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

/// Compte les differentes lettres dans ORIGINALWORD 

int compteur(char* tab){
	int count = 0;
	int i= 1;
	while(i<strlen(tab)){
	if(tab[0]!=tab[i]){
		count++;
	}
	else{}
	i++;
	}
	return count;
}

char* kernel(char* tab){
	printf("le mot que vous devez deviner est %s\n",tab);
	char* cache = malloc(strlen(tab));
	for(int i=0 ; i<strlen(tab)-2 ; i++){
		cache[i] = '*';
	}
	char test;
	int count = strlen(tab)-1;
	printf("\n%s\n",cache);
	printf("vous avez %d tentatives , a vous de jouer : ",count);
	while( count != 0){
		scanf("%c",&test);
		for(int i=0 ; i<strlen(tab) ; i++){
			if(test == tab[i]){
				cache[i]=tab[i];
			}
			else{}
		}
		if(cache == tab){
			printf("CONGRATUATION!!!! vous avez gagné\n");
			break;
		}
		if( count == 0 && cache != tab){
			printf("Vous vennez de perdre le mot que vous avez dû deviner est %s\n",tab);
		}
		else if( count == 0 && cache == tab){
			printf("CONGRATUATION!!!! vous avez gagné\n");
		}
		sleep(1);
		system("clear");
		printf("%s\nIl vous reste %d coups\n",cache,count);
		
		scanf("%c",&test);
		count--;
		
	}
	
	
	return cache;
}
