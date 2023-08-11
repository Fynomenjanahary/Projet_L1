#ifndef __LIBETUDIANT_H__
#define __LIBETUDIANT_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nom[300];
	char prenom[300];
	char tel[300];
	char mail[300];
	char adresse[300];
	char date[300];
	char lieu[300];
	char anne[300];
	char genre[300];
	char cin[300];
	char url[300];
	
}Etudiant;


int count_line(int count , FILE *file);
char** SepareeMot(char*mot,char ch);
Etudiant* taking( FILE *file , int count);
Etudiant* triage(Etudiant* Info , int count);
FILE* submit(Etudiant* Info , int count);
#endif
