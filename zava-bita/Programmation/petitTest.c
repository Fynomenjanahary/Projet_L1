#include<stdio.h>
#include<stdlib.h>
typedef struct coordonnees coordonnees;
	struct coordonnees
	{
		int x;
		int y;
	};
	
int main(){
	printf("int = %ld octets\n", sizeof(int));
	printf("char = %ld octets\n", sizeof(char));
	printf("float = %ld octets\n", sizeof(float));
	printf("double = %ld octets\n", sizeof(double));
	
	printf("coordonnees = %ld octets\n",sizeof(coordonnees));
	//void* malloc(size_t 4);
	int* memoireAllouee = NULL;
	memoireAllouee = malloc(sizeof(int));
	printf("memoireAllou = %p\n",memoireAllouee);
	if(memoireAllouee == NULL){
		exit(0);
	}
	printf("Quel est ton age ? ");
	scanf("%d",memoireAllouee);
	printf("alors vous avez %d ans\n",*memoireAllouee);
	free(memoireAllouee);
	//int nombre;
	

	return 0;
}
