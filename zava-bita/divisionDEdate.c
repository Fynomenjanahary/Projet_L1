#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int estvirgule(char * tab);

int main(){
	char* date1 = malloc (50);
	date1 = "23/05/2023";
	char* date2 = malloc (50);
	date2 = "23/05/2023";
	int position = estvirgule(date1);
	
	
	
	
	return 0;
}

int estvirgule(char * tab){
	int position=0;
	for(int i=0 ; i<strlen(tab) ; i++){
		if(tab[i]=='/'){
			position=i;
			break;
		}
	}
	char* par1 = malloc(position);
	for(int i =0 ;i<position ; i++){
		par1[i]=tab[i];
	}
	printf("%s\n",par1);
	int posi1=0
	for(int i=(position) ; i<strlen(tab) ; i++){
		if(tab[i]=='/'){
			posi1=i;
			break;
		}
	}
	char* par2 = malloc(position);
	int i=0; 
	int k=position+1;
	while(i<posi1 && k<posi1){
		par2[i]=tab[k];
		i++;
		k++;
	}
	printf("%s\n",par2);
	for(int i=position+1 ; i<strlen(tab) ; i++){
		if(tab[i]=='/'){
			position=i;
			break;
		}
	}
	char* par3 = malloc(position);
	for(int i =0 ;i<position ; i++){
		par3[i]=tab[i];
	}
	printf("%s\n",par3);
	return position;
}

