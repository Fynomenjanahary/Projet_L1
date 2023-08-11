#include<stdio.h>
void changeU(int dim , float *u);
void display(int dim , float u[] , float *v);
float result(int dim, float *u, float v[]);		// float *u : u = &u[0]
int main(){
	printf("c'est un programme qui permet de calculer le produit scalaire de 2 vecteurs\n");
/// Données
	int   dim=3;				// La dimension du tableau
	float u[3]={1., 2., 3.},	// Déclaration de tableau de type float
		  v[3]={1., 4., 5.};
	float prod=0.35;			// Le produit scalaire
	changeU(dim,u);
/// Calcul
/*
	prod = 0;
	for(int i=0 ; i<dim ; i++){
		prod += (u[i]*v[i]);
	}
*/
	prod = result(dim , u , v);
/// Sortie

	display(dim , u , v);
	printf("\nLe produit scalaire de u et v est %.f\n", prod);

	return 0;
}
void changeU(int dim , float *u){
	//u[0]=0;
	//*u = 0;
	//u[2]=1;					// notation tableau
	*(u+2)=1;					// notation tableau
}
void display(int dim , float u[] , float *v){
	printf("\nu = \n");
	for(int i=0 ; i<dim ; i++){
		//printf("u[%d]=%.f\n",i,u[i]);
		printf("u[%d]=%.f\n",i,*(u+i));
		}
	printf("\nv = \n");
	for(int i=0 ; i<dim ; i++){
		printf("v[%d]=%.f\n",i,v[i]);
		}
}
float result(int dim , float *u , float v[]){
	float prod = 0;
	for(int i=0 ; i<dim ; i++){
		prod += (u[i]*v[i]);
	}
	
		return prod;
}
