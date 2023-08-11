#include <stdio.h>
int main() {
	char* si;
	printf("what's your name\n");
	scanf("%s",&si);
	printf("hello %s\n", &si);
	return 0;
}
