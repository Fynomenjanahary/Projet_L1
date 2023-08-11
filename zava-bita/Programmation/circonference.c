#include<stdio.h>
#define PI 3.14
int main(){
	printf("calcul de la circonference d'un cercle\n");
	float	rayon=1,	// le rayon u cercle		
			circonf=0;	// la circonférence du cecle
// Entreé de données
	printf("Entrez le rayon du cercle: ");
	scanf("%f",&rayon);
// Traitement de données
	circonf = 2*PI*rayon;

// Sortie de données
	printf("rayon = %f\ncirconference = %f\n", rayon, circonf); 

	return 0;
}
