/// char to int débuggué

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* allocation();
char* remplissage(char* tab);
int compterTaille(char* tab);
int puissance(int iva , int avo);
int enlevement(char *tab , int taille);

int main(){
	char* string=NULL;
	int taille=0;
	int chiffre=0;
	
	string=allocation();
	string=remplissage(string);
	taille=compterTaille(string);
	chiffre=enlevement(string , taille);
	printf("%d\n",chiffre);
	
	free(string);
	return 0;
}
char* allocation(){
	char* tab = malloc(50);
	
	return tab;
}

char* remplissage(char* tab){
	printf("entrez la chaine:");
	retour:
	fgets(tab , 50 , stdin);
	for(int i=0 ; i<strlen(tab) ; i++){
		if(tab[i]<48 || tab[i]>57){
			printf("la chaine comporte d' autre caractere que des chiffres !!!\ntry again!!!\n");
			goto retour;
		}
		else break;
	}
	
	return tab;
}

int compterTaille(char* tab){
	int taille=-1;
	for(int i=0 ; i<50 ; i++){
		if(tab[i]!='\0'){
			taille++;
		}
		else break;
	}
	printf("la taille de cette string est égale à %d\n",taille);
	return taille;
}

int miraculous(char car){
	return(car -'0');
}

int enlevement(char *tab , int taille){
	//int a=0
	int chiffre=0;
	for(int i= 0 ; i<taille ; i++ ){
		chiffre += miraculous(tab[taille-(i+1)])* pow(10,i);
		printf("ici %d\n",chiffre);
	}

	return chiffre;
}
