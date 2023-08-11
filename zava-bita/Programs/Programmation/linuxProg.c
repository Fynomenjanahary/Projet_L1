#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char com[20]="nano";
	char nom[10];
	printf("entrez le nom que vous voulez :");
	scanf("%s",nom);
	strcat(com," ");
	strcat(com,nom);
	int choix;
	printf("1 : langage c\n2 : langage shell\nother : text simple\n");
	scanf("%d",&choix);
	if(choix==1){
		strcat(com,".c");
		system(com);
		char compilation[40]="gcc";
		strcat(compilation," ");
		strcat(compilation,nom);
		strcat(compilation,".c");
		strcat(compilation," ");
		strcat(compilation,"-o");
		strcat(compilation,nom);
		system(compilation);
		
		char executable[20]="./";
		strcat(executable,nom);
		system(executable);
	}
	else if(choix==2){
		system(com);
	
		char permission[30]="chmod";
		char qui[10]="+x";
		strcat(permission," ");
		strcat(permission,qui);
		strcat(permission," ");
		strcat(permission,nom);
	
		system(permission);
	
		char execution[20]="./";
		strcat(execution,nom);
		system(execution);
	}
	else{
		system(com);
	}
	return 0;
}
