#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	printf("Content-Type: text/html\n\n");
	
	char *query_string = malloc(500);
	query_string = getenv("QUERY_STRING");
	
	int* erreur=malloc(sizeof(int)*1);
	sscanf(query_string,"%*[^=]=%d",erreur);
	
	if(*erreur == 1){
		printf("<head><meta http-equiv=\"refresh\" content=\"3;url=http://www.fifaliantsoa.com/form.html\"><meta charset=\"UTF-8\"><title>data</title></head>");
		printf("<body><h1>Diso ny mot de pass</h1></body>\n");
	}
	else if(*erreur == 2){
		printf("<head><meta http-equiv=\"refresh\" content=\"3;url=http://www.fifaliantsoa.com/form.html\"><meta charset=\"UTF-8\"><title>data</title></head>");
		printf("<body><h1>Diso ny username</h1></body>\n");
	}
	else if(*erreur == 3){
		printf("<head><meta http-equiv=\"refresh\" content=\"3;url=http://www.fifaliantsoa.com/form.html\"><meta charset=\"UTF-8\"><title>data</title></head>");
		printf("<body><h1>Aucun utilisateur de ce nom!!!</h1></body>\n");
	}
	
	return 0;
}
