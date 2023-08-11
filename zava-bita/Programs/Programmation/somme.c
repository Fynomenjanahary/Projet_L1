#include<stdio.h>

int main(){
	printf("cacul de 1+2+...+n\n");
/// Données
	
		int n=1,		// la limite de la somme
			somme=0,	// la somme à calculer
			i=0;		// l'entier à cumuler
	while(n!=0){	
		printf("entrez n=");
		scanf("%d",&n);
		
/// Calcul
		somme=0;
		for(int i=1; i<=n; i++){
			somme += i;	
			printf("dans la boucle i=%d et s=%d\n",i ,somme);
	}
	printf("en dehors de la boucle i=%d\n",i);
/// Sortie
		printf("la somme de %d premier est= %d\n", n, somme);
		
	}
	return 0;
}
