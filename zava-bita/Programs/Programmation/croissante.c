#include <stdio.h>
int main(){
	int tab[10];
	for (int i=0; i<10; i++){
		printf("Entrer valeur n° %d: ", i+1);
		scanf("%d", &tab[i]);
	}
	for(int i = 0; i < 10; i++) {
		for(int j = 9; j >=i+1; j--) {
			if (tab[i] < tab[j]) {
				int temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
		} 
	}

	/*for(int i = 0; i < 50; i++) {
		for(int j = i +1; j < 50; j++) {
			if (n[i] > n[j]) {
				int temp = n[i];
				n[i] = n[j];
				n[j] = temp;
			}
		} 
	}*/
	for (int i = 0; i<10; i++) 
		printf("%d  ", tab[i]);
	
	

	return 0;
}
