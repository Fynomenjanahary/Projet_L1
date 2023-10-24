#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	printf("Content-Type: text/html\n\n");
	
	char *query_string = malloc(200);
	query_string = getenv("QUERY_STRING");
	
	FILE *file = fopen("journal.csv","r");
	FILE *redi = fopen("redirect.txt","w");
	char tmp[20];
	fprintf(redi,"%d",1);
	
	if(fgets(tmp,19,file)==NULL){
		printf("	<meta http-equiv='refresh' content='0;url=http://www.fifaliantsoa.com/form.html'>");
	}
	else{
	
	char *user= malloc(300),*pwd=malloc(200);
	
	char *line = malloc(600);int i;
	
	char *name = malloc(300),*pass = malloc(200);
	
	sscanf(query_string,"user=%[^&]&anana=%[^\n]",user,pwd);
	rewind(file);
	
	
	while(fgets(line,600,file) != NULL){
		sscanf(line,"%*[^,],%*[^,],%*[^,],%[^,],%[^\n]",name,pass);
		if(strcmp(name,user)==0 && strcmp(pwd,pass)==0){break;}
		else{}
	}
	
	if(strcmp(name,user)==0 && strcmp(pwd,pass)==0){
			strcat(user,".txt");
			FILE *connex = fopen(user,"w");
			fprintf(connex,"%s",name);
			fclose(connex);
			printf("<head><meta http-equiv=\"refresh\" content=\"0;url=http://www.fifaliantsoa.com/cgi-bin/search.cgi?name=%s\"><meta charset=\"UTF-8\"><title>check</title></head>",name);
		}
	else{
		if(strcmp(name,user)==0 && strcmp(pwd,pass)!=0) i=1;			else if(strcmp(name,user)!=0 && strcmp(pwd,pass)==0) i=2;
		else if(strcmp(name,user)!=0 && strcmp(pwd,pass)!=0) i=3;
		printf("<head><meta http-equiv=\"refresh\" content=\"0;url=http://www.fifaliantsoa.com/cgi-bin/erreur.cgi?retour=%d\"><meta charset=\"UTF-8\"><title>check</title></head>",i);
	}
	
	fclose(file);fclose(redi);
}
	return 0;
} 

