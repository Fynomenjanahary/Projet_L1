#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int positionSlash(char* tab , int position);
char* separetab(char* tab , int posiSlash1);
int estvirgule(char * tab);
int jecompte(char* tab , int position , int posiSlash1);
char* separationTotale(char* tab ,int position , int posiSlash1);
int miraculous(char car);
double charToDouble(char* tab , int position , int compte);
char* temps(double jour , char* tab);

int main(){
	char* string = malloc (50);
	string = "23,7/05/2023";
	int position=0;
	int posiSlash1=0;
	posiSlash1=positionSlash(string , position);
	char* avant;
	avant = separetab(string , posiSlash1);
	position=estvirgule(avant);
	int compte=0;
	compte=jecompte(string , position , posiSlash1);
	string = separationTotale(string , position , posiSlash1);
	
/// Vérification de la suppression de qlq characteres
/*
	for(int a=0 ; a<strlen(string); a++){
			printf("%c",string[a]);
		}
*/
	double leavadika;
	leavadika=charToDouble(avant , position , compte);
	string = temps(leavadika , string );
	for(int a=0 ; a<strlen(string); a++){
			printf("%c",string[a]);
		}

	free(string);
	free(avant);
	return 0;
}

int positionSlash(char* tab , int position){
	int posiSlash1;
	for(int i=0 ; i<strlen(tab) ; i++){
		if(tab[i]=='/'){
			posiSlash1=i;
			break;
		}
	}
	//printf("ici %d\n",posiSlash1);
	return posiSlash1;
}

char* separetab(char* tab , int posiSlash1){
	char* tabio=NULL;
	tabio = malloc (25);
	for(int i=0 ; i<posiSlash1 ; i++){
		tabio[i]=tab[i];
	}
/// Vérifie la copie du charactere avant le premie slash
     
	for(int a=0 ; a<strlen(tabio); a++){
			printf("%c",tabio[a]);
		}
	printf("\n");
	return tabio;
}
   
int estvirgule(char * tab){
	int position=0;
	for(int i=0 ; i<strlen(tab) ; i++){
		if(tab[i]=='.'|| tab[i]==',' || tab[i]==';'){
			position=i;
			printf("le separateur se trouve dans la %deme ligne du tableau\n",position);
		}
	}
	return position;
}

int jecompte(char* tab , int position , int posiSlash1){
	int compte=0;
	for(int i=position ; i<posiSlash1 ; i++){
		compte++;
	}
	//printf("ici compte %d\n",compte);
	return compte-1;
}

char* separationTotale(char* tab ,int position , int posiSlash1){
	char* array1 = malloc(10);
	for(int i=0 ; i<position ; i++){
		array1[i]=tab[i];
	} 
	char* array2 = malloc(20);
	int j=posiSlash1;
	int k=0;
	while(j<strlen(tab) && k<(strlen(tab)-position)){
		array2[k]=tab[j];
		j++;
		k++;
	}
	strcat(array1 , array2);
	
	return array1;
} 

int charToInt(char car){
	return(car -'0');
}

/*int puissance(int iva , int avo);
	int valiny=1;
	for(int i=0 ; i<avo ; i++){
		valiny *= iva;
	}
	return valiny;
}*/

double charToDouble(char* tab , int position , int compte){
	double chiffre=0;
	int i= strlen(tab)-1;
	int a=0;
	while(i>position && a<strlen(tab)-1-position){
		chiffre += charToInt(tab[i])* pow(10,a);
		i--;
		a++;
		//printf("%f\n",chiffre);
	}
	chiffre=chiffre*pow(10 , -compte);
	//printf("%f\n",chiffre);
	return chiffre;
}

char* temps(double jour , char* tab){
	char* temps=malloc(50);
	int heure = jour *24;
	int minute = (jour *24 -heure)*60; 
	int seconde = (((jour *24 -heure)*60)-minute)*60;
	
	sprintf(temps ,"     %d : %d : %d ",heure,minute,seconde);
	strcat(tab , temps);
	
	return tab;
}
