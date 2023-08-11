#include<stdio.h>
int main(){
	char nom[20];
	char prenom[20];
	int age;

	printf("quel est ton nom?\n");
	scanf("%s",nom);
	printf("et ton prenom?\n");
	scanf("%s",prenom);
	printf("quel age as tu?\n");
	scanf("%d",&age);

	printf("salut %s %s qui a ans %d\n", nom, prenom, age);
	printf("%p",&nom[0]);

	int jour=0;
	jour = age*365;
	printf("\n vous avez vecu %d  jours", jour);
	return 0;
}
