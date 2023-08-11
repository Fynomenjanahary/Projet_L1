#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* allocation();
char* remplissage(char* tab);
int estvirgule(char * tab);
char** separetab(char*tab , int position);
double puissance(double iva , int avo);
int miraculous(char car);
double charToDouble(char *tab , char** gold , int position);

int main(){
	char* string=NULL;
	int position=0;
	char** recup=NULL;
	double final=0;
	string=allocation();
	string=remplissage(string);
	position=estvirgule(string);
	recup = separetab(string , position);
	final=charToDouble(string , recup , position);
	printf("vous avez un nombre de type double égale à %f\n",final);
 printf("\nPREUVE : 2 * %f = %f\n",final,final*2);

	free(string);
	free(recup);
	return 0;
}
char* allocation(){
	char* tab = malloc(50);
	
	return tab;
}

char* remplissage(char* tab){    
	printf("entrez la chaine:");
	//retour:
	fgets(tab , 50 , stdin);
	for(int qlq=0 ; qlq<strlen(tab) ; qlq++){
		if(tab[qlq]=='\n'){
			tab[qlq]='\0';
		}
	}
	/*int estvirgule=0;
	for(int i=0 ; i<strlen(tab) ; i++){
		if(tab[i]==44 || tab[i]==46 || tab[i]==59){
			estvirgule+=1;
			for(int j=i+1 ; j<strlen(tab) ; j++){
				if(tab[i]==tab[j]){
					printf("je vous rappelle que la string ne doit comporter qu' un seul séparateur (soit , ou ; ou .)!!!\n try again");
					goto retour;
				}
				
				else printf("la position %d qui contient le séparateur\n",estvirgule);
		}
		else break;
	}*/
	return tab;
}

int estvirgule(char * tab){
	int position=0;
	for(int i=strlen(tab)-1 ; i>=0 ; i--){
		if(tab[i]=='.' || tab[i]==',' || tab[i]==';'){
			position=strlen(tab)-(1+i);
			printf("le separateur se trouve au %deme position par rapport a la derniere caractere du chaine\n",position);
		}
	}
	return position;
}

char** separetab(char*tab , int position){
	char** recup;
	recup = malloc(50*sizeof(char*));
	for(int i=0 ; i<50 ; i++){
		recup[i]=malloc(50);
	}
	int j=0;
	
	while(j<(strlen(tab)-position-1)){
		recup[1][j]=tab[j];
		j++;
	}
	int f=strlen(tab)-position;
	int g=0;
	while(g<(strlen(tab)-position) && f<strlen(tab)){
		recup[2][g]=tab[f];
		g++;
		f++;
	}
/// Verifie la séparation
	/*for(int a=0 ; a<strlen(tab); a++){
		for(int b=0 ; b<strlen(tab) ; b++){
			printf("%c\t",recup[a][b]);
		}
		printf("\n");
	}*/
	return recup;
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

//int jecompte(char)

double puissance(double iva , int avo){
	double nombre=1;
		for(int i=0 ; i<avo ; i++){
			nombre*=iva;
		}
	
	return nombre;
}

int miraculous(char car){
	return(car -'0');
}

double charToDouble(char* tab , char** gold , int position){
	double chiffre1=0;
	double chiffre2=0;
	double final=0;
	int i= strlen(tab)-position-2;
	int a=0;
	while(i>=0 && a<strlen(tab)-position-1){
		chiffre1 += miraculous(gold[1][i])* puissance(10,a);
		printf("ici %f\n",chiffre1);
		i--;
		a++;
	}
	int b=position-1 ;
	int c=0;
	while(b>=0 && c<=(position-1)){
		chiffre2 += miraculous(gold[2][b])* puissance (10,c);
		printf("ici %f\n",chiffre2);
		b--;
		c++;
	}
	chiffre2=chiffre2 * (1/puissance(10,position));
	final = chiffre1 + chiffre2;
	
	return final;
}
