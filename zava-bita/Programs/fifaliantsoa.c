#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	
	int nbr;
	nbr = 1+ (int)(100.0*rand() / (RAND_MAX));
	int dev=0;
	int compteur=7;
	
	do{
		printf("entrez le nombre mystere :");
		scanf("%d",&dev);
		
			if(nbr>dev){
				printf("le nombre est plus grand et il reste %d essais\n",compteur-1);
			}
		
			else if(nbr<dev){
				printf("le nombre est plus petit et il vous reste %d essais\n",compteur-1);
			}
		
			else if((nbr=dev)){
				printf("Bravo, vous venez de le deviner!\n");
			}
		
		compteur--;
		
	}while(nbr != dev && compteur != 0);
		
	if((compteur==0)){
				printf("vouz venez de perdre\n");	
		}
		
	return 0;
}
