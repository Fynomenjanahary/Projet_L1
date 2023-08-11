#include <stdio.h>
int tableau(int *tab);
float moyenne(int *tab);
int main(){
	int tab [5];
	float lamoyenne;
	lamoyenne=moyenne(tab);
	printf("la moyenne des valeurs dans le tableau est %f",lamoyenne);
	
	return 0;
}

int tableau(int *tab){
	int somme;
	for(int i=0; i<5 ; i++){
		printf("tab[%d]=",i);
		scanf("%d",&tab[i]);
		somme += tab[i];
	}
	return somme;
}
float moyenne(int *tab){
	int somme;
	somme=tableau(tab);
	float lamoyenne;
	lamoyenne = (float)somme/2;
	return lamoyenne;
}
