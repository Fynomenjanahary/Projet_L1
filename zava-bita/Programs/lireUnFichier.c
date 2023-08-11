#include <stdio.h>
#define max 100

int main(){
	char ligne[max];
	FILE *pfichier;
	pfichier = fopen("testbe","r");
	while (! feof(pfichier)) {
		fgets(ligne,max,pfichier);
		if (! feof(pfichier))
			printf("j'ai lu :%s\n",ligne);
	}
	fclose(pfichier);
	
	return 0;
}
