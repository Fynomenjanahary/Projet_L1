#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int testa(char *a){
	
	int i=0;
	while(a[i] !='\0'){
		if(!isdigit(a[i])){
			return 0;
		}
		else{
			i++;
		}
	}

	return 1;
}


int testa1(char *a){
	char t[] = "1" , s[] = "2", r[]= "3";
	int i=0;
	while(a[i] !='\0'){
		if(!isdigit(a[i])){
			return 0;
		}
		else if(strcmp(t , a) == 0){
			return 1;
		}
		else if(strcmp(s , a) == 0){
			return 1;
		}
		else if(strcmp(r , a) == 0){
			return 1;
		}
		else if(isdigit(a[i])){
			return 0;
		}
		else{
			i++;
		}
	}
	
	return 1;
}


int testa2(char *a){
	char t[] = "1" , s[] = "2" , u[] = "3" , v[] = "4";
	int i=0;
	while(a[i] !='\0'){
		if(!isdigit(a[i])){
			return 0;
		}
		else if(strcmp(t , a) == 0){
			return 1;
		}
		else if(strcmp(s , a) == 0){
			return 1;
		}
		else if(strcmp(u , a) == 0){
			return 1;
		}
		else if(strcmp(v , a) == 0){
			return 1;
		}
		else if(isdigit(a[i])){
			return 0;
		}
		else{
			i++;
		}
	}
	return 1;
}
