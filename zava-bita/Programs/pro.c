#include <stdio.h>
#include <math.h>
#include <string.h>
char itoascii (int i);
char lmtoascii (char c);
char LMtoascii (char d);
int main(){
	/*int a=7 , b=3;
	b =++a;
	printf("a = %d \tb = %d\n",a,b);
	
	a=7; b=3;
	b = a++;
	printf("a = %d\tb = %d\n",a,b);
	
	int c=2;
	printf("a-b-c= %d\ta-(b-c)= %d\n",a-b-c ,a-(b-c));
	
	printf("a/b/c= %d\ta/(b/c)= %d\n",a/b/c ,a/(b/c));*/
	/*char texte[20]="Hello World!";
	printf("Longueur du texte = %ld\n", strlen(texte));
	for(int i=0 ; i<=strlen(texte); i++){
		printf("%c\t",texte[i]);
	}
	printf("\nCodes ASCII:\n");
	for(int i=0 ; i<=strlen(texte) ; i++){
		printf("%d\t",texte[i]);
	}
	
	printf("\nLe texte à l'envers:\n");
	for(int i=strlen(texte) ; i>=0 ; i--){
		printf("%c",texte[i]);
	}*/
	printf("Les digits decimaux : \n");
	for(int i=0 ; i<10 ; i++){
		printf("%c = %d\t", itoascii(i), itoascii(i));
	}
	
	printf("\nLes lettres minuscules :\n");
	for(int i=0 ; i<26 ; i++){
		printf("%c = %d\t", lmtoascii(i), lmtoascii(i));
	}
	
	printf("\nLes lettres majuscules :\n");
	for(int i=0 ; i<26 ; i++){
		printf("%c = %d\t", LMtoascii(i), LMtoascii(i));
	}
	return 0;
}
char itoascii (int i){
	return '0' + i;
}

char lmtoascii (char c){
	return 'a' + c;
}

char LMtoascii (char d){
	return 'A' + d;
}
