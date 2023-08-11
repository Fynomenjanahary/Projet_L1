#include <stdio.h>
#include <stdlib.h>

void testerLesnombresInferieurAn(int n);

int main(){
	int n=0;
	printf("\e\t\t[35mSOMME DES NOMBRES PREMIERS INFÉRIEUR OU ÉGALE À n\e[0m\n");
	printf("entrez n=");
	scanf("%d",&n);
	
	testerLesnombresInferieurAn(n);
	
	return 0;
}
void testerLesnombresInferieurAn(int n){
	int somme=0;
	for(int i=2 ; i<=n ; i++){
		int tmp=1;
		for(int j=2 ; j<i ; j++){
			if(i%j==0){
				tmp=0;
			}
		}
		if(tmp==1){
			somme+=i;
		}
	}
	printf("la somme des nombres premiers inférieurs ou égale à %d est %d\n",n,somme);
}
