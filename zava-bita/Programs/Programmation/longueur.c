#include<stdio.h>
#include<math.h>
int main(){
	float a=0,
	      f=0,
	      l=0,
	      e=0;
	printf("entrez la distance entre les deux cables a=");
	scanf("%f",&a);

	printf("\n le fleche f= ");
	scanf("%f",&f);
	e=pow(((2*f)/a),2);
	l= (a +(a* 2)/3 * e);
	printf("\n la longueur de la cable est l= %f\n",l);

	return 0;
}
