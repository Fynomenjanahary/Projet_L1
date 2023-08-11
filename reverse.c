#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* reversing(char* string , char* reverse , float taille);
void check(char* string , char* reverse);

int main(){
	char string[200];
	printf("veiullez entrer la chaine: ");
	scanf("%s",string);
	float taille = strlen(string);
	char *reverse;
	reverse = malloc(taille+1);
	
	/*printf("%f ceil\n",ceil((taille/2)));
	printf("%f floor",(floor(taille/2)));*/
	reverse = reversing(string , reverse , taille);
	printf("voici l'inverse du string : %s\n",reverse);
	check(string,reverse);
	
	return 0;
}

char* reversing(char* string , char* reverse , float taille){
	if((int)taille%2==0){
		for(int i=0 ; i<(int)taille/2 ; i++){
			reverse[i]=string[(int)(taille-1-i)];
			reverse[(int)(taille-1-i)] = string[i];
		}
	}
	else{
		for(int i=0 ; i<(int)taille/2 ; i++){
			reverse[i]=string[(int)(taille-1-i)];
			reverse[(int)(taille-1-i)] = string[i];
		}
		reverse[(int)ceil((taille/2))-1] = string[(int)ceil((taille/2))-1];
	}
	return reverse;
}

void check(char* string , char* reverse){
	if(strcmp(string,reverse)==0)printf("this string is a palindrome\n");
	else printf("this string isn't a palindrome\n");
	
}
