#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int **k;
	int **h;
	int **s;
	int line;
	int i,j;
	printf("entrez le nombres de lignes et de colonnes:");
	scanf("%d",&line);
	
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
	
/// CALCUL DE LA SOMME 
	s = (int**) (malloc(line*sizeof(int*)));
	for(int i=0 ; i<line ; i++)
	{
		s[i] = malloc ( line * sizeof(int));
	}
	if(s==NULL)
	{
		exit (1);
	}
	
	printf("\nla somme des deux matrices :\n");
	
	for(i=0;i<line;i++)
	{
		for(j=0;j<line;j++)
		{
			s[i][j] = (k[i][j])+(h[i][j]);
			printf("%d ",s[i][j]);
		}
		printf("\n");
	}
	
	free(k);
	free(h);
	free(s);
	
	return 0;
}
