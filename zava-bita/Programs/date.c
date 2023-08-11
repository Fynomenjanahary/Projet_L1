#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char** allouerChar2D(int n,int m);
char** mampisaraka(char separator, char *at);
int charToInt(char car);
char intToChar(int entier);
char* enlevement(char* string);
char* famadihana(char** temps , char** heure , char* string);

int main(){
	char* string = malloc (150);
	string = "23/05/2023 16:48";
	char** temps=NULL;
	char separator=' ';
	temps = mampisaraka(separator , string);

	char** heure=NULL;
	char delim=':';
	heure = mampisaraka(delim , temps[1]);

	string=famadihana(temps , heure , string);
	for(int a=0 ; a<strlen(string); a++){
			printf("%s\t",string);
		}
	
	return 0;
}



char ** allouerChar2D(int n,int m){
	char ** tmp;
	tmp = (char**)malloc(n*sizeof(char*));
	for(int i =0; i<n ;i++){
		tmp[i] = malloc(m);
	}
	return tmp;
}

char** mampisaraka(char separator, char *at){
	char **temps=NULL;
	int j=0,k=0,isa=0;
	for(int i=0;i<strlen(at);i++){
		if(at[i]==separator) isa++;
	}
	temps=(char**)calloc(sizeof(char*),isa+1);
	for(int i=0;i<isa+1;i++){
		*(temps+i)=(char*)calloc(1,50);
	}
	for(int i=0;i<strlen(at);i++){
		if(at[i]==separator){
			k++;j=0;
		}
		else{
			*(*(temps+k)+j) = at[i];
			j++;
		}
	}
	return temps;
}

int charToInt(char car){
	return(car -'0');
}

char intToChar(int entier){
	return (entier+'0');
}

int positionSlash(char* tab){
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

char* enlevement(char* temps){
	char* moitie = malloc(50);
	int positionSlash1=positionSlash(temps);
	int k=0;
	for(int i=positionSlash1 ; i<strlen(temps) ; i++){
		moitie[k]=temps[i];
		k++;
	}
	/*for(k=0 ; k<strlen(moitie) ; k++){
			printf("%c\n",moitie[k]);
		}*/
	
	return moitie;
}

char* famadihana(char** temps , char** heure , char* string){
	int partminute1=0;
	int partminute2=0;
	partminute1=charToInt(heure[1][0]);
	partminute2=charToInt(heure[1][1]);
	partminute1=partminute1*pow(10 , 1);
	int minute=partminute1+partminute2;
	
	int partheure1=0;
	int partheure2=0;
	partheure1=charToInt(heure[0][0]);
	partheure2=charToInt(heure[0][1]);
	partheure1=partheure1*pow(10 , 1);
	int Heure=partheure1+partheure2;
	
	double total=(double)minute/60;
	total=total+Heure;
	
	int seconde=total*3600;
	double jour=((double)seconde/3600)/24;
	printf("ici %f\n",jour);
	
	char** separationTotale;
	char mpampisaraka='/';
	separationTotale=mampisaraka(mpampisaraka , temps[0]);
	
	int Jour=jour*pow(10 , 1);
	printf("ici %d\n",Jour);
	/*char* intToJour=calloc(1,10);
	for(int i=0 ; i<1 ; i++){
		intToJour[i]=intToChar(jour);
	}
	strcpy(string , separationTotale[0]);
	strcat(string , ".");
	strcat(string , intToJour);
	intToJour=enlevement(temps[0]);
	strcat(string , intToJour);
	*/
	return string;
}
