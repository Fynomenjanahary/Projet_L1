#include<stdio.h>
int main(){
	int n;
	printf("entrer un nombre n=");
	scanf("%d", &n);
	int m=n-1;
	
	while (m>=1){
		n=n*m;
		m--;
	}
	printf("Factoriel: %d", n);
}
