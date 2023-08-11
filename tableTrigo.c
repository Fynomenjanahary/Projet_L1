#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define r 3.141592653589/180

int main(){
	FILE * file;
	file = fopen("tableTrigo.csv","a+");
	fprintf(file,"%s , %s , %s , %s , %s , %s , %s , %s","en dégré","en radians","COSINUS","SINUS","TANGENTE","ARCcos","ARCsin","ARCtan\n");
	double tmp;
	for(int i=0 ; i<=360 ; i++){
		tmp = i*r;
		fprintf(file,"%d , %f , %f , %f , %f , %f , %f , %f\n",i,tmp,cos(tmp),sin(tmp),tan(tmp),acos(tmp),asin(tmp),atan(tmp)),"\n";
	}
	fclose(file);
	return 0;
}
