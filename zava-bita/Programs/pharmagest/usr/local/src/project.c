#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "pharmacie.h"

int main(){
	int langue=1;
	int utilisateur=2;
	int faire=0;
	//system("chmod -R 777 .");
	menuOpening();
	opening2();
	b:
	langue=menuLangue();
	if(langue==3)
		exit(1);
	start:
	n:
	utilisateur=ChoixUtilisateur(langue);
	if(utilisateur==3)
		goto b;
	
	if(login(langue,utilisateur)==1){
		goto start;
	}
	
	if(utilisateur == 1){
		begin:
		faire=job(utilisateur,langue);
		if(faire==4){
		sleep(0.5);
		system("clear");
		goto n;
		}
		ajout(faire, utilisateur, langue);
		system("clear");
		goto begin;
	}
	
	faire=job(utilisateur,langue);
	ajout(faire, utilisateur, langue);
	//system("clear");
	
	return 0;
}




	
	
	
