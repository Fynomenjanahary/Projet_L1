#include<stdio.h>
int main(){
	float f=0, c=0;			//variable
	printf("entrez f =");	//le nbr à convertisser
	scanf("%f",&f);
	
	c=0.55556*(f-32);		//calcul

	printf("\n%f degree Fahrenheit est = %f degree Celscuis",f,c);

	return 0;
}
