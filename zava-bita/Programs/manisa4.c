/* code misy erreur ny Mandrindra */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char **allocation2d(int line, int rows);
char *tenyGasy(char *isa, char **ambany);
int asciiToInt(char *at);
char *mampitohy(char **tohizana, char **ambony, int len);
char **split(char separator, char *at);
int *avadika(char *miditra);

int main(){
	char **mizara=NULL;
	char testa[]="2912";
	char *valiny=NULL;
	char **ambany=allocation2d(9,6);
	*(ambany+0)=" ";ambany[1]="iray ";ambany[2]="roa ";ambany[3]="telo ";ambany[4]="efatra ";ambany[5]="dimy ";ambany[6]="enina ";ambany[7]="fito ";ambany[8]="valo ";ambany[9]="sivy ";
	char **ambony=allocation2d(8,10);
	ambony[0]=" amby";ambony[1]="polo";ambony[2]="njato";ambony[3]="arivo";ambony[4]="alina";ambony[5]="hetsy";ambony[6]="tapitrisa";ambony[7]="lavitrisa";
	valiny=tenyGasy(testa,ambany);
	//printf("%s\n",valiny);
	mizara=split(' ',valiny);
	char *aty=NULL;
	aty=mampitohy(mizara,ambony,strlen(testa));
	printf("%s : %s\n",testa,aty);
	free(aty);
	free(ambany);
	free(ambony);
	return 0;
}
char **split(char separator, char *at){
	char **splited=NULL;
	int j=0,k=0,count=0;
	for(int i=0;i<strlen(at);i++){
		if(at[i]==separator) count++;
	}
	splited=(char**)calloc(sizeof(char*),count+1);
	for(int i=0;i<count+1;i++){
		*(splited+i)=(char*)calloc(1,50);
	}
	for(int i=0;i<strlen(at);i++){
		if(at[i]==separator){
			k++;j=0;
		}
		else{
			*(*(splited+k)+j) = at[i];
			j++;
		}
	}
	return splited;
}

char *mampitohy(char **tohizana, char **ambony,int len){
	char *valiny=NULL;
	//~ char *transition=NULL;
	//~ transition=calloc(1,100);
	valiny=(char*)calloc(1,500);
	for(int i=0;i<len;i++){
		if(strcmp(tohizana[i],"")==0) continue;
		if(len==1) *(ambony+i)="";
		strcat(strcat(valiny,*(tohizana+i)),*(ambony+i));
		strcat(valiny," ");
	}
	return valiny;
	
}
char **allocation2d(int line, int rows){
	char **folo=NULL;
	folo=(char**)calloc(sizeof(char*),line);
	for (int i = 0; i < line; i++){
		*(folo+i)=(char*)calloc(1,rows);
	}
	return folo;
}
int *avadika(char *miditra){
	int *mivadika=NULL;
	mivadika=(int*)calloc(sizeof(int),strlen(miditra));
	int at=asciiToInt(miditra);
	for (int i = 0; i < strlen(miditra); i++){
		mivadika[i]=at%10;at/=10;
	}
	return mivadika;
}

char *tenyGasy(char *isa, char **ambany){
	char *valiny=NULL;
	valiny=calloc(1,100);
	int *t=NULL;
	t=avadika(isa);
	for(int i=0;i<strlen(isa);i++){
		switch(t[i]){
			case 0:
				strcat(valiny,ambany[0]);
				break;
			case 1:
				strcat(valiny,ambany[1]);
				break;
			case 2:
				strcat(valiny,ambany[2]);
				break;
			case 3:
				strcat(valiny,ambany[3]);
				break;
			case 4:
				strcat(valiny,ambany[4]);
				break;
			case 5:
				strcat(valiny,ambany[5]);
				break;
			case 6:
				strcat(valiny,ambany[6]);
				break;
			case 7:
				strcat(valiny,ambany[7]);
				break;
			case 8:
				strcat(valiny,ambany[8]);
				break;
			case 9:
				strcat(valiny,ambany[9]);
				break;
			}
		}
		return valiny;
	
}
int asciiToInt(char *at){
	int result=0,j=0;
	for(int i=strlen(at)-1;i>=0;i--){
		result+=(*(at+i)-48)*pow(10,j);
		j++;
	}
	return result;
}
