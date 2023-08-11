#include <stdio.h>

void entrerTab(int* tab);
void afficheTab(int* tab);
void triTab(int* tab);
void afficheTab2(int* tab);
int main(){
	int tab[10];
	entrerTab(tab);
	afficheTab(tab);
	triTab(tab);
	
	afficheTab2(tab);
	
	return 0;
}
void entrerTab(int* tab){
	for (int i=0; i<10; i++){
		scanf("%d", &tab[i]);
	}
}
void afficheTab(int* tab){
	entrerTab(tab);
	for (int i=0; i<10; i++){
		printf("Entrer valeur n° %d:%d\n", i+1,tab[i]);
	}
}
void triTab(int* tab){
	entrerTab(tab);
	afficheTab(tab);
	for(int i = 0; i < 10; i++) {
		for(int j = i +1; j < 10; j++) {
			if (tab[i] > tab[j]) {
				int temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
		} 
	}
	
}
void afficheTab2(int* tab){
	for (int i = 0; i<10; i++){ 
		printf("%d  ", tab[i]);
	}
}

void triHeritina(int* tab){
	for(int i = 0; i < 10; i++) {
		for(int j = 9; j >=i+1; j--) {
			if (tab[i] < tab[j]) {
				int temp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = temp;
			}
		} 
	}
}

