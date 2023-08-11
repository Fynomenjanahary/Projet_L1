#include<stdio.h>
#include<math.h>
void function(int a,int b,int c,float x1,float x2,float delta);
int main(){
	printf("resolution de ax^2+bx+c=0 dans R\n");
	int a=0, b=2.65, c=-4;
	float x1=768.987, x2=61;
	float delta;
/*
/// Entrée de données
	while(1){
		printf("entrez a=");
		scanf("%d",&a);
		printf("entrez b=");
		scanf("%d",&b);
		printf("entrez c=");
		scanf("%d",&c);
/// Calcul de(s) solution(s) et réponses
		deltat = b*b -4*a*c;
		if(deltat >= 0){
			x1 = (-b-sqrt(deltat))/(2*a);
			x2 = (-b-sqrt(deltat))/(2*a);
			printf("les solutions sont:\n");
		printf("x1= %f\nx2= %f\n", x1, x2);
		}
		else{
			printf("Il n'y aucun solution réelle");
		}
	}
*/
	function (a,b,c,x1,x2,delta);
	return 0;
}
void function(int a,int b,int c,float x1,float x2,float delta){ 
	/// Entrée de données
	while(1){
		printf("entrez a=");
		scanf("%d",&a);
		printf("entrez b=");
		scanf("%d",&b);
		printf("entrez c=");
		scanf("%d",&c);
/// Calcul de(s) solution(s) et réponses
		delta = b*b -4*a*c;
		if(delta >= 0){
			x1 = (-b-sqrt(delta))/(2*a);
			x2 = (-b-sqrt(delta))/(2*a);
			printf("les solutions sont:\n");
		printf("x1= %f\nx2= %f\n", x1, x2);
		}
		else{
			printf("Il n'y aucun solution réelle");
		}
	}
}
