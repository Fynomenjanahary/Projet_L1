#include <stdio.h>
#include <stdlib.h>

int main(){
	float inf,sup;
	printf("notre fonction a comme forme : f(x) = x²\n");
	printf("borne inférieur : ");scanf("%f",&inf);
	printf("borne supérieur : ");scanf("%f",&sup);
	while(inf>=sup){
		system("clear");
		printf("borne inférieur : %.2f\n",inf);
		printf("borne supérieur : ");scanf("%f",&sup);
		system("clear");
	}
	printf("f(x)= x² pour tout x € [%.2f , %.2f]\n",inf,sup);
	int nbr;
	printf("entrez l'amplitude : ");scanf("%d",&nbr);
	float amp = (sup-inf)/nbr;
	FILE *file;
	file = fopen("fichier.csv","a+");
	for(float i=inf ;i<=sup ; i+=amp){
		fprintf(file,"%f,%f\n",i,i*i);
	}
	fclose(file);
	
	return 0;
}
