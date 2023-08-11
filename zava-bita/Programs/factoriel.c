#include <stdio.h>
int facto(int n);

int main(){
	int n;
	printf ("ce programme calcul le factoriel d'un entier n!\n");
	printf("entrez le nombre que vous voulez savoir quel est son factoriel : ");
	scanf("%d",&n);
	printf("le factoriel de %d est %d \n",n,facto(n));
	return 0;
}
/// c'est une fonction récurssive!!!
int facto(int nombre){
	if(nombre==2) return 2;
	return nombre * facto(nombre-1);
	
}
