#include <stdio.h>
#include <stdlib.h>
int entrerNombre();
int* allouer(int n);
void entrerValTab(int *qlq , int n);
void triage(int *qlq , int n);
void afficheTri(int *qlq , int n);
void afficheMax(int *qlq , int n , int N);

int main(){
	int n;
	int N;
	int *tab=NULL;
	printf("entrez le nombre des nombres :");
	n=entrerNombre();
	tab=allouer(n);
	printf("entrez les éléments du tableau : \n");
	entrerValTab(tab , n);
	printf("les éléments du tableau après tri:");
	triage(tab , n);
	afficheTri(tab , n);
	printf("\nentrez le nombre des maximums que vous voulez afficher :");
	N=entrerNombre();
	printf("\nles %d maximums du tableau sont : ",N);
	afficheMax(tab , n , N);
	
	free(tab);
	return 0;
}
int entrerNombre(){
	int n;
	scanf("%d",&n);
	return n;
}
int* allouer(int n){
	int *qlq=NULL;
	qlq = (int*) malloc(n*sizeof(int));
	if(qlq==NULL)
		exit (1);
	return qlq;
}
void entrerValTab(int *qlq , int n){
	for(int i=0 ; i<n ; i++){
		scanf("%d",&qlq[i]);
	}
}
void triage(int *qlq , int n){
	int tmp=0;
	for(int i=0 ; i<n ; i++){
		for(int j=i+1 ; j<n ; j++){
			if(qlq[i]<qlq[j]){
				tmp=qlq[j];
				qlq[j]=qlq[i];
				qlq[i]=tmp;
			}
		}
	}
}
void afficheTri(int *qlq , int n){
	for(int i=0 ; i<n ; i++){
		printf("%d ", qlq[i]);
	}
}
void afficheMax(int *qlq , int n , int N){
	int max=0;
	for(int i=0 ; i<N ; i++){
		if(max < qlq[i]){
			printf("%d ",qlq[i]);
		}
	}
}
