#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int* identify(char* date1);
char** alloue2DChar(int taille);
char** split(char* date1,int* indice); 
int charToint(char car);
int puissance(int j,char** tab);
float  finaly(char** tab,char** Tb);

int main (){
	char date1[]= "00/03/2023";
	char date[]="00/04/2023";
	int taille=0;
	int* daty=(int*)malloc(taille*sizeof(int));
	char** tab=NULL;                 
	int* and=(int*)malloc(taille*sizeof(int));
	char** tb=NULL;
	float nbre=0.0;
	
	tab=alloue2DChar(taille);
	daty=identify( date1);
	and=identify(date);
	tab=split( date1,daty);
	tb=split( date,and);
	nbre=finaly(tab,tb);
	printf("\n%f",nbre);
	return 0;
}

	
int* identify(char* date1){
	int* indice=malloc(2*sizeof(int));
	int j=0;
	for(int i=0; i<strlen(date1); i++){
		if(date1[i] == '/'){	
			indice[j]=i;
			j++;
		}	
	}
	return indice;
}

					
char** alloue2DChar(int taille){
	char** tab;
	tab=(char**)malloc((taille+1)*sizeof(char*));
	for(int i=0;i<(taille+1); i++){
		tab[i]=malloc(10);
	}
	return tab;
}

		 	
char** split(char* date1,int* indice){
	char** tab=NULL;
	tab=alloue2DChar(2);
	for(int i=0; i<indice[0];i++){
		tab[0][i]=date1[i];	
	}	
	for(int j=indice[0]+1,i=0; j<indice[1];i++,j++){
		tab[1][i]=date1[j];
	}
	for(int j=indice[1]+1 ,i=0; j<strlen(date1); i++,j++){
		tab[2][i]=date1[j];	
	}		
	return tab;	
	
}				
 
int charToint(char car){
	return ( car-'0');
}	


int puissance(int j,char** tab){               
	int nbre=0;
	int puiss=-1;
	for(int i=strlen(tab[j])-1; i>=0; i--) {
		puiss+=1;
		nbre+=charToint(tab[j][i])* pow(10,puiss);
	}
	return nbre;
}


float finaly(char** tab,char** Tb){
	int jour=0,mois=0,ans=0;
	int  jour1=0,mois1=0,ans1=0;

	float nbre=0.0;
	jour=puissance(0,tab);					
	mois=(puissance(1,tab))*30;
	ans=(puissance(2,tab))*365;
	jour= jour+mois+ans;

	jour1=puissance(0,Tb);					
	mois1=(puissance(1,Tb))*30;
	ans1=(puissance(2,Tb))*365;
	jour1=jour1+mois1+ans1;
	
	nbre=jour/(float)jour1;
	
	return nbre;
}
