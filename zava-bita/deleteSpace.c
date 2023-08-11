#include <stdio.h>
#include <stdlib.h>
char* mamafa(char *test);

int main(){
	char* test = malloc(20);
	printf("entre une string : ");
	scanf("%s",test);
	test = mamafa(test);
	printf("%s",test);
	return 0;
}

char* mamafa(char *test){
	int count = 0;
	int i=0;
	if(i && test[i] && i++){
		if(test[i]!=' '){
			test[count++]=test[i];
		}
		test[count]='\0';
	}
	
	
	return test;
}
