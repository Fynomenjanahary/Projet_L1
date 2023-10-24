#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char time[100];
    char open[100];
    char user[100];
}Lien; 

int jourSemaine(int y, int m, int d) {
    if (m < 3) {
        m += 12;
        y -= 1;
    }

    // Séparation de l'année en deux parties (exemple : 2023 -> J=20, K=23)
    int K = y % 100;
    int J = y / 100;

    // Ajustement pour les années bissextiles
    int ajustement = (13 * (m + 1)) / 5 + K + (K / 4) + (J / 4) - 2 * J;

    // Si le mois est janvier (1) ou février (2), on considère ces mois comme les mois 13 et 14 de l'année précédente.
    if (m == 13 || m == 14) {
        ajustement += 1;
    }

    // Calcul du jour de la semaine (0 pour samedi, 1 pour dimanche, 2 pour lundi, etc.)
    int h = (d + ajustement) % 7;

    return h;
}


int fampitahana(char* moi, int mois){
	char same[12][5]={"Jan","Fev","Mar","Avr","Mey","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	for(int i=0;i<12; i++){
		if(strcmp(moi,same[i])==0){
			mois=i;
			break;
		}
	}
	return mois;
}

char* volana(int mois){
	char* volana = malloc(20);
	char same[12][20]={"Janoary","Feboroary","Martsa","Aprily","May","Jona","Jolay","Aogositra","Septambra","Oktobra","Novambra","Desambra"};
	for(int i=0;i<12; i++){
		if(mois==i){
			strcpy(volana,same[i]);
			break;
		}
	}
	
	return volana;
}

char* correspondance_jour(int jour){
	char* j= malloc(20);
	
	char day[7][20]={"Alatsinainy","Talata","Alarobia","Alakamisy","Zoma","Sabotsy","Alahady"};
	for(int i=0 ;  i<7 ; i++){
		if(jour == i){
			strcpy(j,day[i]);
			break;
		}
	}
	return j;
}

char* separe_date(char *alaina){
	char* date = malloc(50);
	char *moi = malloc(20),*j = malloc(20) , *time = malloc(15) , *tmp = malloc(3);int jour, day ,mois=0;
	sscanf(alaina,"%[^ ] %[^ ] %s",moi,j,time);
	strcpy(tmp,j);
	jour = atoi(j);
	mois = fampitahana(moi,mois);
	moi = volana(mois);
	day = jourSemaine(2023, mois, jour);
	j = correspondance_jour(day);
	strcpy(date , j);
	strcat(date , " ");
	strcat(date , tmp);
	strcat(date , " ");
	strcat(date , moi);
	strcat(date , " ");
	strcat(date , time);
	
	return date;
}

Lien * get(int * num_u, char *search , int* link , char *name){
	char * query_string;
	query_string = malloc(200);
    query_string = getenv("QUERY_STRING");

	*link=1;
	
	sscanf(query_string,"%*[^&]&lien=%d",link);
	    
    if (query_string != NULL) {
        if(strchr(query_string, '&')){
			sscanf(query_string,"%[^=]=%[^&]",name,search);
		}
		else{
			sscanf(query_string,"%*[^=]=%s",search);
		}
    }
	
	FILE *retour;
	retour = fopen("/var/log/auth.log","r");

	if (retour == NULL){
		printf("<h1>"
			"TSY METY"
			"</h1>"
		);
		exit (1);
	}
	
	int j=0;
	Lien *alaina;
	alaina = malloc(111111*sizeof(Lien));
	char line[900];
	char *daty = malloc(80);
	
	while (fgets(line, sizeof(line), retour) != NULL) {
		if((strstr(line,"opened") || strstr(line,"closed")) && strstr(line,search)!= NULL){
			if (sscanf(line,"%[^m]m%*[^:]:%*[^:]:%*[^:]:%[^f]f%*[^r]r%*[^r]r%[^\n]",daty,alaina[j].open,alaina[j].user)==3) {
					daty = separe_date(daty);
					strcpy(alaina[j].time,daty);
					//~ printf("ito %s-------%s--------%s\n"
						//~ ,alaina[j].time,alaina[j].open,alaina[j].user
					//~ );
					j++;
					
			}
		}
		
    }
    *num_u = j;
    return alaina;
} 
