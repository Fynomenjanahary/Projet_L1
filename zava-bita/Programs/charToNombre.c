#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* allocation();
char* remplissage(char* tab);
int compterTaille(char* tab);
int puissance(int iva , int avo);
int miraculous(char car);
int enlevement(char *tab , int taille);

int main(){
	char* string=NULL;
	int taille=0;
	int chiffre=0;
	
	string=allocation();
	string=remplissage(string);
	taille=compterTaille(string);
	chiffre=enlevement(string , taille);
	printf("vous avez un entier naturel égale à %d\n",chiffre);
	printf("preuve : 2 * %d = %d\n",chiffre,chiffre*2);
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
	printf("la taille du stringt que vous avez entrez est %d\n",taille);
	return taille;
}

int puissance(int iva , int avo){
	int nombre=1;
	if(avo==0){
		iva=1;
	}
	else{
		for(int i=0 ; i<avo ; i++){
			nombre*=iva;
		}
	}
	
	return nombre;
}

int miraculous(char car){
	return(car -'0');
}

int enlevement(char *tab , int taille){
	//int a=0
	int chiffre=0;
	for(int i= 0 ; i<taille ; i++ ){
		chiffre += miraculous(tab[taille-(i+1)])* puissance(10,i);
	}

	return chiffre;
}
