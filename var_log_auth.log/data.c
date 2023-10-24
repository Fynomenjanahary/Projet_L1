#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	
	printf("Content-Type: text/html\n\n");
	
	char *query_string = malloc(500);
	query_string = getenv("QUERY_STRING");
	
	char mail[500]="null",last[500]="Null",first[500]="Null",user[100]="Null",pw[100]="Null";
	
	printf("%s ito \n",query_string);
	//return 0;
	sscanf(query_string,"%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^\n]",mail,last);
	sscanf(query_string,"%*[^t]t%*[^&]&%*[^=]=%[^&]&%*[^=]=%[^&]&%*[^=]=%[^\n]",first,user,pw);
	
	
	FILE* file;
	file = fopen("journal.csv","a+");
	
	fprintf(file,"%s,%s,%s,%s,%s\n",mail,last,first,user,pw);
	
    printf("<head><meta http-equiv=\"refresh\" content=\"0;url=http://www.fifaliantsoa.com/form.html\"><meta charset=\"UTF-8\"><title>data</title></head>");
	
	fclose(file);
	return 0;
}
