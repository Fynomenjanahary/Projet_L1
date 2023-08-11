#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int seconde=0;
	int minute=0;
	int heure=0;
	
	for(heure=0;heure<24;heure++){
		for(minute=0;minute<60;minute++){
			for(seconde=0;seconde<60;seconde++){
				printf("%02d:%02d:%02d\n",heure,minute,seconde);
				sleep(1);
				system("clear");
			}
		}
	}
	
	
		return 0;
}
