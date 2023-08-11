#include<stdio.h>
int sumOdd(int n);
void displayResult(int somme);
int main(){
	int n=1,
		somme=0;
		
	while(n!=0){	
	printf("entrez n=");
	scanf("%d",&n);
	
	somme = sumOdd(n);
	/*somme=0;
	for(i=1 ;i<=(2*n-1) ;i+=2){	//si pair i=0
		somme+=i;
	}
	
	while(i<=n){// Si impair i<=(2*n-1) et
		somme+=i;
		i++;// i+=2
	}*/
	//printf("1+2+...+n=%d\n",somme);//+2*n-1
	displayResult(somme);
	}
	return 0;

}
int sumOdd(int n){
	int somme=0 ,i=0;
	for(i=1 ,somme=0 ;i<=(2*n-1) ;i+=2){
		somme+=i;
	}
		return somme;
}
void displayResult(int somme) {
	printf("1+2+...+n=%d\n",somme);
}
