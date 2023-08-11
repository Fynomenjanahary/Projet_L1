#include <stdio.h>
#include <stdlib.h>
#include "vecteurFoisScalaire.h"

int main(){
	int* vect1;
	vect1 = remplissage(vect1);
	printf("le produit scalaire est : \n");
	for(int i=0 ; i<3 ; i++){
		printf("%d\n",vect1[i]);
	}
	return 0;
}

