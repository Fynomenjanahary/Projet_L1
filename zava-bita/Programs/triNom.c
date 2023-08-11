#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main() {
    char **nom,**maj;
    int n=0;
    char m[]="0";
    printf("entrez le nombre de nom que vous voulez saisir:");
    fgets(m, 10, stdin);
    n = atoi (m);
    

/**************************INITIALISATION******************************/

    nom=(char**) (malloc ( n * sizeof(char*)));
    for(int i=0 ; i<n ; i++) {
        nom[i] = malloc(50*sizeof(char));
    }
    if(nom==NULL) {
        exit(-1);
    }
    printf("entrez les nom:\n");
    for(int i=0 ; i<n ; i++) {
        printf("%d:",i+1);
        fgets(nom[i],50,stdin);
    }

/***************************TRANSFORMATION*****************************/

    maj=(char**) (malloc ( n * sizeof(char*)));
    for(int i=0 ; i<n ; i++) {
        maj[i] = malloc(50*sizeof(char));
    }
    if(maj==NULL) {
        exit(-1);
    }
    printf("\nles nom que vous avez saisi en majuscule:\n");
    for(int i=0 ; i<n ; i++){
		for(int j ; j<strlen(nom[i]) ; j++){
			maj[i][j] = toupper (nom[i][j]);
		}
		printf("%d: %s",i+1, maj[i]);
	}

/************************TRAITEMENT et TRIAGE**************************/
    
    for(int i=0 ; i<n ; i++) {
        for(int p=i+1 ; p<n ; p++) {
            if((strcmp(nom[i],nom[p]))>0) {
                char tmp[50];
                strcpy(tmp,nom[p]);
                strcpy(nom[p],nom[i]);
                strcpy(nom[i],tmp);
                strcpy(tmp,maj[p]);
                strcpy(maj[p],maj[i]);
                strcpy(maj[i],tmp);
            }
        }
    }

/******************************RESULT**********************************/

    printf("\n\nvoici les nom que vous avez saisissez mais dans l'ordre:\n");
    for(int i=0 ; i<n ; i++) {
        printf("%d:%s",i+1,nom[i]);
    }
    free(nom);
    free(maj);
    
    return 0;
}
