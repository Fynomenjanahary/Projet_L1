#include<stdio.h>
#include<math.h>
void displayResult(float a,float b,float c,float delta,float x1,float x2);
float calcdelta(float a,float b,float c);
void resolve(float a,float b,float c, float* delta, float* x1, float* x2);
float resolve1(float a,float b,float c,float* x1, float* x2);
void getdata(float* a,float* b,float* c);
int main(){
	printf("Resolution de ax²+bx+c=0 dans R\n");
/// Données
	float a=1, b=2 ,c=1;	// les coeff. de l'équation
	float x1=167, x2=678.7;	// les solutions éventuelles
	float delta=1;			// le discriminant de l'équation
	
/// Calcul
	//resolve(a ,b , c , &delta, &x1, &x2);
	while(1){
		getdata(&a, &b, &c);	// pour récupérer des valeur de a, b, c
		delta=calcdelta(a,b,c);
		delta = resolve1(a ,b , c , &x1, &x2);	// pour résoudre l'équation
/*	
	if(delta<0){
			printf("Il n'y a pas de solution reelle\n");
	}
	else{
		x1=(-b-sqrt(delta))/2*a;
		x2=(-b+sqrt(delta))/2*a;
	}*/
/// Sortie
		displayResult(a,b,c,delta,x1,x2);		// pour afficher les résultats
	}
	return 0;
}
void getdata(float* pa,float* b,float* c){
	printf("entrez a=");
		scanf("%f",pa);
		printf("entrez b=");
		scanf("%f",b);
		printf("entrez c=");
		scanf("%f",c);
}
	
float resolve1(float a,float b,float c,float* x1, float* x2){
	float delta=678.4567;
	delta=calcdelta(a,b,c);
	if(delta>=0){	
		*x1=(-b-sqrt(delta))/(2*a);
		*x2=(-b+sqrt(delta))/(2*a);
	}
	return delta;
}

void resolve(float a,float b,float c, float* delta, float* x1, float* x2){
		*delta=calcdelta(a,b,c);
	if(*delta>=0){	
		*x1=(-b-sqrt(*delta))/(2*a);
		*x2=(-b+sqrt(*delta))/(2*a);
	}
}

float calcdelta(float a,float b,float c){
	float delta = 0;
	delta = (b*b) - (4*a*c);
	
	return delta;
}

void displayResult(float a,float b,float c,float delta,float x1,float x2){
	if(delta<0){
		printf("Il n'a pas de solution reelle\n");
	}
	else{
	printf("Avec les coefficients sont\na=%f\nb=%f\nc=%f\n",a,b,c);
	printf("on a deux solutions x1=%f et x2=%f\n", x1,x2);
	}
}	
