#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main(){
	char D[12];
	scanf("%s",D);
	for(int i=0;i<strlen(D);i++){
		if(isalpha(D[i]))
			printf("%d",D[i]-'A');
		else printf("%c",D[i]);
	}
}
*/

int main(){
	char T[12];
	scanf("%[^\n]",T);
	for(int i=0;i<strlen(T);i++)
		printf("%c",T[i]>=65?T[i]-17:T[i]);
}
