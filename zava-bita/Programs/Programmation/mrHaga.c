#include <stdio.h>
void valeur(int *tab);
void affiche(int *tab);
int main(){
	int tab[10]={1,2,1,2,3};
	valeur(tab);
	affiche(tab);
	
	return 0;
}
void valeur(int *tab){
	for(int i=0 ; i<10 ; i++){
		printf("entrer une valeur=");
		scanf("%d",tab+i);
	}
}
void affiche(int *tab){
	for(int i=0 ; i<10 ; i++){
		printf("tab[%d]=%d\n",i,tab[i]);


	}



}

