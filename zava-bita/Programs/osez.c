#include <stdio.h>
#include <string.h>

int main(){
	char s[10];
	int i = 65;
	//int code;
	sprintf(s , "%d" , i);
	printf("s = %s\n",s);
	
	char c[2]="2";
	int n=0;
	sscanf(c, "%d" , n);
	printf("n=%d\n",n);
	
	
	return 0;
}
