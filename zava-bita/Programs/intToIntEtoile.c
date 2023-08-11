#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int taille(int nbr);
int* intToIntEtoile(int integer , int* entier , int manisa);

int main(){
	int nbr = 543210;
	int manisa = taille(nbr);
	int* tabDEint = malloc (sizeof(int)*manisa);
	tabDEint = intToIntEtoile(nbr , tabDEint , manisa);
	
	return 0;
}

int taille(int nbr){
	int manisa=0;
	
	while(nbr != 0){
		nbr /= 10;
		++manisa;
	}
	return manisa;
}

int* intToIntEtoile(int integer , int* entier , int manisa){

	for(int i=manisa-1 ; i>=0 ; i--){
		entier[i]=integer % 10;
		integer /= 10;
	}
	for(int i=0 ; i<manisa ; i++){
		printf("%d - ",entier[i]);
	}
	
	return entier;
}


/**********DIVISION DE DEUX DATE***********/


