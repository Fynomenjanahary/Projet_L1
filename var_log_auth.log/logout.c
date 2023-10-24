#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	printf("Content-Type: text/html\n\n");
	
	char *query_string = malloc(500);
	query_string = getenv("QUERY_STRING");
	
	char *fichier = malloc(200);
	
	sscanf(query_string,"%*[^=]=%s",fichier);
	
	
	if(remove(fichier)==0){
		printf("bien !!!!!!\n");
		printf("<html><head><meta http-equiv=\"refresh\" content=\"0;url=http://www.fifaliantsoa.com/form.html\"></head></html>");
	}
	else{printf("%s mince alors !!!!!\n",fichier);}
	return 0;
}
