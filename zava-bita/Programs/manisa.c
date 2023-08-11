/* dernière version */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

int miraculous(char car);
char*** Allouer3D();
char** Allouer2D();
char* condition(char* tab , char*** nbr);
char* fanisana(char* tab);

int main(){
	char* isa=malloc(20);
	long long nbr=0;
 printf("Ampidiro ny isa : ");
	char* tenyMalagasy=malloc(500);
	scanf("%lld",&nbr);
	sprintf(isa ,"%lld",nbr);
	tenyMalagasy=fanisana(isa);
	printf("%s\n",tenyMalagasy);
	
	free(isa);
	return 0;
}

int miraculous(char car){
	return(car -'0');
}

char*** Allouer3D(){
	char*** tab;
	tab=malloc(8*sizeof(char**));
	for(int i=0 ; i<8 ; i++){
		tab[i]=Allouer2D();
	}
	return tab;
}

char** Allouer2D(){
	char** mot=(char**)malloc(10*sizeof(char*));
	for(int i=0; i<10; i++){
		mot[i] = (char*)malloc(20);
	}
	return mot;
}

char* condition(char* tab , char*** nbr){
	char* teny=calloc(1,50);
	if(tab[strlen(tab)-1]=='0')	strcat(teny , "aotra");
	else{
		strcat(teny , nbr[0][miraculous(tab[strlen(tab)-1])]);
	}
	return teny;
}

char* condition2(char* tab , char*** nbr , char* since , char* pendant){
	char* teny=calloc(1,50);
	if(tab[strlen(tab)-1]!='0'){	
		teny = condition(tab , nbr);									/// Raha tsy zero le isa farany
		if(tab[strlen(tab)-2]=='1')		strcat(teny , pendant);			// raha 1 le ao aloha 
		else		strcat(teny , since);									// raha tsy 1 le ao aloha
	}
	else if(tab[strlen(tab)-1]=='0'){}
	strcat(teny , nbr[1][miraculous(tab[strlen(tab)-2])]);
	return teny;
}

char* condition3(char* tab , char*** nbr , char* since , char* pendant , char* depuis){
	char* teny=calloc(1,150);
	if(tab[strlen(tab)-2]!='0'){
		if(tab[strlen(tab)-1]!='0'){		  teny = condition2(tab , nbr , since , pendant);if(tab[strlen(tab)-3]=='1'){strcat(teny , since);}else{strcat(teny , depuis);}}
		else{teny = condition2(tab , nbr , since , pendant);if(tab[strlen(tab)-3]=='1'){strcat(teny , since);}else{strcat(teny , depuis);}}}
 else{
  if(tab[strlen(tab)-1]!='0'){    teny = condition(tab , nbr);if(tab[strlen(tab)-3]=='1'){strcat(teny , since);}else{strcat(teny , depuis);}}
  else{} 
 }
 strcat(teny , nbr[2][miraculous(tab[strlen(tab)-3])]);
			
	return teny;
}

char* condition4(char* tab , char*** nbr , char* since , char* pendant , char* depuis){
	char* teny=calloc(1,150);
	if(tab[strlen(tab)-3]!='0'){teny = condition3(tab , nbr , since , pendant , depuis);strcat(teny , depuis);}
	else {
		if(tab[strlen(tab)-2]=='0'){
			if(tab[strlen(tab)-1]=='0'){}
			else {teny = condition(tab , nbr);strcat(teny , depuis);}
		}
		else{teny = condition2(tab , nbr , since , pendant);strcat(teny , depuis);}
	}
	strcat(teny , nbr[3][miraculous(tab[strlen(tab)-4])]);
	return teny;
}

char* condition5(char* tab , char*** nbr , char* since , char* pendant , char* depuis){
	char* teny=calloc(1,150);
	if(tab[strlen(tab)-4]!='0'){teny = condition4(tab , nbr , since , pendant , depuis);strcat(teny , depuis);}
	else{
		if(tab[strlen(tab)-3]!='0'){teny = condition3(tab , nbr , since , pendant , depuis);strcat(teny , depuis);}
		else{teny = condition3(tab , nbr , since , pendant , depuis);}
	}
  strcat(teny , nbr[4][miraculous(tab[strlen(tab)-5])]);
 return teny;
}

char* condition6(char* tab , char*** nbr , char* since , char* pendant , char* depuis){
	char* teny=calloc(1,150);
	if(tab[strlen(tab)-5]!='0'){teny = condition5(tab , nbr , since , pendant , depuis);strcat(teny , depuis);}
 else{
  if(tab[strlen(tab)-4]=='0'){teny = condition4(tab , nbr , since , pendant , depuis);}
  else{teny = condition4(tab , nbr , since , pendant , depuis);strcat(teny , depuis);}
 }
 strcat(teny , nbr[5][miraculous(tab[strlen(tab)-6])]);		
	return teny;
}

char* separer(char* tab , int n){
	char* temp=calloc(1,5);
	for(int i=0 ; i<n ; i++){
		temp[i]=tab[i];
	}
	return temp;
}

char* condition7a9(char* tab , char*** nbr , char* since , char* pendant , char* depuis , char* que){
	char* teny=calloc(1,150);
	char* tmp=calloc(1,30);
	tmp=separer(tab , (strlen(tab)-6));
	if(strlen(tmp)==1)			tmp=condition(tmp , nbr);
	else if(strlen(tmp)==2)		tmp=condition2(tmp , nbr , since , pendant);
	else                        tmp=condition3(tmp , nbr , since , pendant , depuis); 
	strcat(tmp , que);
	strcpy(teny , "");
	if(tab[strlen(tab)-6]=='0'){	teny = condition6(tab , nbr , since , pendant , depuis);}
	else    teny = condition5(tab , nbr , since , pendant , depuis);
	strcat(teny , tmp);
	return teny;
}

char* fanisana(char* tab){
	char* teny=calloc(1,200);
 char* valiny=calloc(1,250);
	char*** nbr=Allouer3D();
	char since[10]=" amby ";
	char depuis[10] =" sy ";
	char pendant[16]=" ambin'ny ";
	char que[15]=" tapitrisa";
	char qlq[20]=" lavitrisa";
	strcpy(nbr[0][0],"\0");
	strcpy(nbr[0][1],"iray");
	strcpy(nbr[0][2],"roa");
	strcpy(nbr[0][3],"telo");
	strcpy(nbr[0][4],"efatra");
	strcpy(nbr[0][5],"dimy");
	strcpy(nbr[0][6],"enina");
	strcpy(nbr[0][7],"fito");
	strcpy(nbr[0][8],"valo");
	strcpy(nbr[0][9],"sivy");
	strcpy(nbr[1][0],"\0");
	strcpy(nbr[1][1],"folo");
	strcpy(nbr[1][2],"roapolo");
	strcpy(nbr[1][3],"telopolo");
	strcpy(nbr[1][4],"efapolo");
	strcpy(nbr[1][5],"dimapolo");
	strcpy(nbr[1][6],"enipolo");
	strcpy(nbr[1][7],"fitopolo");
	strcpy(nbr[1][8],"valopolo");
	strcpy(nbr[1][9],"sivy folo");
	strcpy(nbr[2][0],"\0");
	strcpy(nbr[2][1],"zato");
	strcpy(nbr[2][2],"roan-jato");
	strcpy(nbr[2][3],"telon-jato");
	strcpy(nbr[2][4],"efa-jato");
	strcpy(nbr[2][5],"dima-njato");
	strcpy(nbr[2][6],"enin-jato");
	strcpy(nbr[2][7],"fiton-jato");
	strcpy(nbr[2][8],"valon-jato");
	strcpy(nbr[2][9],"sivan-jato");
	strcpy(nbr[3][0],"\0");
	strcpy(nbr[3][1]," arivo");
	strcpy(nbr[3][2]," roa arivo");
	strcpy(nbr[3][3]," telo arivo");
	strcpy(nbr[3][4]," efatra arivo");
	strcpy(nbr[3][5]," dimy arivo");
	strcpy(nbr[3][6]," enina arivo");
	strcpy(nbr[3][7]," fito arivo");
	strcpy(nbr[3][8]," valo arivo");
	strcpy(nbr[3][9]," sivy arivo");
	strcpy(nbr[4][0],"\0");
	strcpy(nbr[4][1]," iray alina");
	strcpy(nbr[4][2]," roa alina");
	strcpy(nbr[4][3]," telo alina");
	strcpy(nbr[4][4]," efatra alina");
	strcpy(nbr[4][5]," dimy alina");
	strcpy(nbr[4][6]," enina alina");
	strcpy(nbr[4][7]," fito alina");
	strcpy(nbr[4][8]," valo alina");
	strcpy(nbr[4][9]," sivy alina");
	strcpy(nbr[5][0],"\0");
	strcpy(nbr[5][1]," iray hetsy");
	strcpy(nbr[5][2]," roa hetsy");
	strcpy(nbr[5][3]," telo hetsy");
	strcpy(nbr[5][4]," efatra hetsy");
	strcpy(nbr[5][5]," dimy hetsy");
	strcpy(nbr[5][6]," enina hetsy");
	strcpy(nbr[5][7]," fito hetsy");
	strcpy(nbr[5][8]," valo hetsy");
	strcpy(nbr[5][9]," sivy hetsy");
	
///****************************************RAHA 1 NY HALAVANY LE STRING******************************************///	
	if(strlen(tab)==1)			teny = condition(tab , nbr);
///****************************************RAHA 2 NY HALAVANY LE STRING*****************************************///
	else if(strlen(tab)==2)		teny = condition2(tab , nbr , since , pendant);
///****************************************RAHA 3 NY HALAVANY LE STRING******************************************///	
	else if(strlen(tab)==3)		teny = condition3(tab , nbr , since , pendant , depuis);
///****************************************RAHA 4 NY HALAVANY LE STRING******************************************///
	else if(strlen(tab)==4)		teny = condition4(tab , nbr , since , pendant , depuis);
///****************************************RAHA 5 NY HALAVANY LE STRING******************************************///
	else if(strlen(tab)==5) 	teny = condition5(tab , nbr , since , pendant , depuis);
///****************************************RAHA 6 NY HALAVANY LE STRING******************************************///
	else if(strlen(tab)==6)		teny = condition6(tab , nbr , since , pendant , depuis);
///****************************************RAHA 7 KA HATRAMIN'NY 9 NY HALAVANY LE STRING****************************************************///
	else if(strlen(tab)>=7 && strlen(tab)<=9)	teny = condition7a9(tab , nbr , since , pendant , depuis , que);
///****************************************RAHA 10 KA HATRAMIN'NY 18 NY HALAVANY LE STRING*************************************************///	
	else if(strlen(tab)==10 /*&& strlen(tab)<=18*/){
		char* tmp=calloc(1,200);
	tmp=separer(tab , (strlen(tab)-9));
	tmp=condition(tmp , nbr);
	/*if(strlen(tmp)==10)				tmp=condition(tmp , nbr);
	else if(strlen(tmp)==11)		tmp=condition2(tmp , nbr , since , pendant);
	else if(strlen(tmp)==12)		tmp=condition3(tmp , nbr , since , pendant , depuis);
	else if(strlen(tmp)==13)		tmp=condition4(tmp , nbr , since , pendant , depuis);
	else if(strlen(tmp)==14)		tmp=condition5(tmp , nbr , since , pendant , depuis);
	else if(strlen(tmp)==15)		tmp=condition6(tmp , nbr , since , pendant , depuis);
	else if(strlen(tmp)>=16)		tmp=condition7a9(tmp , nbr , since , pendant , depuis , que);*/
	strcat(tmp , qlq);
	strcpy(teny , "");
	teny = condition7a9(tab , nbr , since , pendant , depuis , que);
	strcat(teny , depuis);
	strcat(teny , tmp);	
		
	}
	strcat(valiny , teny);
	return valiny;
}
