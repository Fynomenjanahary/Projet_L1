#include<stdio.h>
int main(){
	float n, test;
	int b;
	do{
		printf("entrez n=");
		b = scanf("%f",&n);

		test =n - (int)n;


	}while(!b || test!=0);
	while(!b){
	scanf("%f",&n);}
	return 0;
}
