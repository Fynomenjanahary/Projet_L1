#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** allouer2D();
char*** allouer3D(char*** tab);

int main(){
	char*** tabi=NULL;
	tabi = allouer3D(tabi);
	if(tabi==NULL){
		printf("tsy nety\n");
	}
	else
	printf("oueeeee!!!\n");
	free(tabi);
	return 0;
}

char** allouer2D(){
	char** tab;
	tab = malloc(10*sizeof(char*));
	for(int i=0 ; i<10 ; i++)	tab[i] = malloc(20);
	
	return tab;
}

char*** allouer3D(char*** tab){
	tab=(char***)malloc(8*sizeof(char**));
	for(int j=0 ; j<8 ; j++)	tab[j]=allouer2D();

	return tab;
}

char*** famenoana(char*** nbr){
		strcpy(nbr[0][0],"\0");
	strcpy(nbr[0][1],"raika");
	strcpy(nbr[0][2],"roa");
	strcpy(nbr[0][3],"telo");
	strcpy(nbr[0][4],"efatra");
	strcpy(nbr[0][5],"dimy");
	strcpy(nbr[0][6],"enina");
	strcpy(nbr[0][7],"fito");
	strcpy(nbr[0][8],"valo");
	strcpy(nbr[0][9],"sivy");
	strcpy(nbr[1][0],"\0");
	strcpy(nbr[1][1],"folo");
	strcpy(nbr[1][2],"roapolo");
	strcpy(nbr[1][3],"telopolo");
	strcpy(nbr[1][4],"efapolo");
	strcpy(nbr[1][5],"dimapolo");
	strcpy(nbr[1][6],"enipolo");
	strcpy(nbr[1][7],"fitopolo");
	strcpy(nbr[1][8],"valopolo");
	strcpy(nbr[1][9],"sivy folo");
	strcpy(nbr[2][0],"\0");
	strcpy(nbr[2][1],"zato");
	strcpy(nbr[2][2],"roan-jato");
	strcpy(nbr[2][3],"telon-jato");
	strcpy(nbr[2][4],"efa-jato");
	strcpy(nbr[2][5],"dima-njato");
	strcpy(nbr[2][6],"enin-jato");
	strcpy(nbr[2][7],"fiton-jato");
	strcpy(nbr[2][8],"valon-jato");
	strcpy(nbr[2][9],"sivan-jato");
	
	char mille[10]=" arivo ";
	char milli[10]=" alina ";
	char million[10]=" hetsy ";
	char milliard[10]=" tapitrisa ";
	char millia[10]=" lavitrisa ";
	
	for(int i=3 ; i<9 ; i++){
		for(int j=1 ; j<10 ; j++){
			nbr[i][0]='\0';
			strcat(nbr[i][j] , strcat(nbr[0][j] , ));
	
	
	return tab;
}
