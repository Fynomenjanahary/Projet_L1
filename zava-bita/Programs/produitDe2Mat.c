#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	
	int **k;
	int **h;
	int **p;
	int line;
	int i,j;
	printf("entrez le nombres de lignes et de colonnes:");
	scanf("%d",&line);
	system ("clear");
	
/// La PREMIÈRE MATRICE	
	k = (int**) (malloc(line * sizeof(int*)));
	for(int i=0 ; i<line ; i++)
	{
		k[i] = malloc (line * sizeof(int));
	}
	
	if(k==NULL)
	{
		exit (1);
	}
	
	printf("entrez les éléments de la premieres matrice\n");
	
	for(i=0;i<line;i++)
	{
		for(j=0;j<line;j++)
		{
			printf("ligne(%d) colonne(%d): ", i+1, j+1);
			scanf("%d",&k[i][j]);
		}
	}
	
	printf("les éléments da la première matrice\n");
	for(i=0;i<line;i++)
	{
		for(j=0;j<line;j++)
		{
			printf("%d  ",k[i] [j]);
		}
		printf("\n");
	}
	sleep (2);
	system ("clear");

/// LA DEUXIÈME MATRICE
	
	h = (int**) (malloc(line*sizeof(int*)));
	for(int i=0 ; i<line ; i++)
	{
		h[i] = malloc ( line * sizeof(int));
	}
	if(h==NULL)
	{
		exit (1);
	}
	
	printf("\nentrez les éléments de la deuxièmes matrice\n");
	
	for(i=0;i<line;i++)
	{
		for(j=0;j<line;j++)
		{
			printf("ligne(%d) colonne(%d): ", i+1, j+1);
			scanf("%d",&h[i][j]);
		}
	}
	printf("les éléments da la deuxième matrice\n");
	for(i=0;i<line;i++)
	{
		for(j=0;j<line;j++)
		{
			printf("%d  ",h[i] [j]);
		}
		printf("\n");
	}
	sleep (2);
	system ("clear");
/// CALCUL Du PRODUIT DES DEUX MATRICES
	p = (int**) (malloc(line*sizeof(int*)));
	for(int i=0 ; i<line ; i++)
	{
		p[i] = malloc ( line * sizeof(int));
	}
	if(p==NULL)
	{
		exit (1);
	}
	printf("\nLe produit des deux matrices est:\n");
	for(i=0 ; i<line ; i++)
	{
		for(j=0;j<line;j++)
		{
			p[i][j] = 0;
			for(int l=0 ; l<line ; l++){
				p[i][j]+= k[i][l] * h[l][j];
			}
				printf("%d ",p[i][j]);
		}
		printf("\n");
	}
	
	free(k);
	free(h);
	free(p);
	
	return 0;
}

