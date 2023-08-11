#include <stdio.h>
#include <stdlib.h>
#define ta 5

int** tompotrano();
int** famenoana(int** tab);
int esorina(int det , int** tab);

int main(){
	int** matrice=NULL;
	matrice = tompotrano();
	matrice = famenoana(matrice);
	int det=0;
	printf("le part : %d\n",det=esorina(det , matrice));
	return 0;
}

int** tompotrano(){
	int** tab;
	tab = malloc(3*sizeof(int*));
	for(int i=0 ; i<3 ; i++){
		tab[i]=malloc(ta*sizeof(int));
	}
	
	return tab;
}

int** famenoana(int** tab){
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("ligne(%d) colonne(%d): ", i+1, j+1);
			scanf("%d",&tab[i][j]);
			tab[i][j+3] = tab[i][j];
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<=ta;j++)
		{
			printf("%d\t", tab[i][j]);
		}
		printf("\n");
	}
	
	return tab;
}

int esorina(int det , int** tab){
	int a=0 , b=0 , k=ta-3 , d=a;
	int tmp=1;
	//int part1=0;
	while(a<ta && k<ta){
		while(b<3 && d<=k){
			tmp*=tab[b][d];
			b++;
			d++;
			printf("ici tmp = %d\n",tmp);
		
		}
		det+=tmp;
		a++;
		k++;
		printf("ici det = %d\n",det);
		
	}
	printf("ici %d\n",a);
		
	
	return det;
}
