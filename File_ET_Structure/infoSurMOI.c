#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *file;
	file = fopen("info.txt","a+");
	if(file == NULL){exit(1);}
	// alaina charactere par charactere
	/*char c;
	while(c != EOF){
		c=fgetc(file);printf("%c",c);
	}*/
	printf("rehefa alaina par ligne \n\n");
	char string[256];
	/*while(!feof(file)){
		printf("%s",string);
		fgets(string,255,file);

	}*/
	while(!feof(file)){
		fgets(string,255,file);
		if(!feof(file)){printf("%s",string);}
	}
	char str[2344];
	printf("\n\nnampiasa fscanf : ");
	fscanf(file,"%s\n",str);printf("%s\n",str);
	printf("entrez qlq : ");
	scanf("%s",str);
	fprintf(file,"%s",str);
	
	
	fclose(file);
	
	return 0;
}
