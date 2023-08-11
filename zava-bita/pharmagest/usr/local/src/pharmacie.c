#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
int testa(char *a);
int testa1(char *a);
int testa2(char *a);

void menuOpening(){
	char vert[]="92";
	printf("\033[%sm",vert);
	system("mpg123 -q /usr/share/sounds/pharmagest/tapclavier.mp3 &");
	char a[100]="\t\t\t       _                                     _   ";
	char b[100]="\t\t\t _ __ | |__   __ _ _ __ _ __ ___   __ _  ___(_) ___ ";
	char c[100]="\t\t\t| '_ || '_ | | _` | '_|| '_ ` _  || _` ||__|| || _ | ";
	char d[100]="\t\t\t| |_) | | | | (_| | |  | | | | | | (_| ||(__| || _|";
	char e[100]="\t\t\t| .__||_| |_||__,_|_|  |_| |_| |_||__,_||___|_||___| ";
	char f[100]="\t\t\t|_|  ";

	printf("%s\n",a);
	usleep(500000);
	printf("%s\n",b);
	usleep(500000);
	printf("%s\n",c);
	usleep(500000);
	printf("%s\n",d);
	usleep(500000);
	printf("%s\n",e);
	usleep(500000);
	printf("%s\n",f);
	sleep(2);
	system("\n\t");
	char g[100]="\t\t\t\t     _                  _ _   ";
	char h[100]="\t\t\t\t  __| | ___   _ __ ___ (_) |_ ";
	char i[100]="\t\t\t\t / _` |/ _ | | '_ ` _ || | __|";
	char j[100]="\t\t\t\t| (_| |  __/ | | | | | | | |_";
	char k[100]="\t\t\t\t |__,_||___| |_| |_| |_|_|__ |";
	
	printf("%s\n", g);
	usleep(500000);
	printf("%s\n", h);
	usleep(500000);
	printf("%s\n", i);
	usleep(500000);
	printf("%s\n", j);
	usleep(500000);
	printf("%s\n", k);
	sleep(3);
}

void opening2(){
	system("mpg123 -q /usr/share/sounds/pharmagest/Bienvenue.mp3 &");
	system("sh /usr/share/sounds/pharmagest/anim.sh");
	system("clear");
		char p[100]="\t\t____________________________________________________________________";
	char a[100]="\t\t|    _                                                        _    | ";
	char b[100]="\t\t|  _| |_                                                    _| |_  |  ";
	char c[100]="\t\t| |_   _| $$--------------PHARMACIE DE MIT--------------$$ |_   _| |   " ;
	char d[100]="\t\t|   |_|                                                      |_|   |   ";
	char z[100]="\t\t|__________________________________________________________________|";
	printf("%s\n%s\n%s\n%s\n%s\n%s\n\n",p ,a ,b, c, d, z);
	sleep(1);
	system("clear");
}

int menuLangue(){
	char *langue = NULL;
	langue = (char*)malloc(100*sizeof(char));	
	/*system("cd ; mpg123 -q animationspharma/Bienvenue.mp3 &");
	system("cd ~/MrHaga ; ./anim.sh");
	system("clear");
	sleep(1);*/
	system("mpg123 -q /usr/share/sounds/pharmagest/langue.mp3 &");
	sleep(2.5);
	system("mpg123 -q /usr/share/sounds/pharmagest/language.mp3 &");
	char p[100]="\t\t\t____________________________________________________________________";
	char a[100]="\t\t\t|    _                                                        _    | ";
	char b[100]="\t\t\t|  _| |_                                                    _| |_  |  ";
	char c[100]="\t\t\t| |_   _| $$--------------PHARMACIE DE MIT--------------$$ |_   _| |   " ;
	char d[100]="\t\t\t|   |_|                                                      |_|   |   ";
	char z[100]="\t\t\t|__________________________________________________________________|";
	
	
	//system("cd ; mpg123 -q animationspharma/welcome.mp3 &");
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n\n",p ,a ,b, c, d, z);
	//printf("\t\t\tVeuillez choisissez votre langue / Please choose your language:\n");
	printf("\t\t");
	char lang[100]="Veuillez choisissez votre langue/ Please choose your language:";
		for(int i=0;i<strlen(lang);i++){
		printf("%c", lang[i] );
		usleep(60000);
		fflush(stdout);
		}
		printf("\n");
	printf("\t\t\t\t\t1-FRANÇAIS / FRENCH\n\t\t\t\t\t2-ANGLAIS / ENGLISH\n\t\t\t\t\t3-Quitter / Leave\n");
	printf("Réponse / Answer:");scanf("%s", langue);
	system("clear");
	
	while(testa1(langue) == 0){
		char p[100]="\t\t\t____________________________________________________________________";
		char a[100]="\t\t\t|    _                                                        _    | ";
		char b[100]="\t\t\t|  _| |_                                                    _| |_  |  ";
		char c[100]="\t\t\t| |_   _| $$--------------PHARMACIE DE MIT--------------$$ |_   _| |   " ;
		char d[100]="\t\t\t|   |_|                                                      |_|   |   ";
		char z[100]="\t\t\t|__________________________________________________________________|";
		printf("%s\n%s\n%s\n%s\n%s\n%s\n\n",p ,a ,b, c, d, z);
		printf("\t\t\tVeuillez choisissez votre langue/ Please choose your language:\n");
		printf("\t\t\t\t\t1-FRANÇAIS / FRENCH\n\t\t\t\t\t2-ANGLAIS / ENGLISH\n\t\t\t\t\t3-Quitter / Leave\n");
		system("mpg123 -q /usr/share/sounds/pharmagest/validinfr.mp3 &");
		sleep(2);
		system("mpg123 -q /usr/share/sounds/pharmagest/validinen.mp3 &");
		printf("\n\tNB:Je vous prie de saisir une entrée valide ! / Please enter a valid entry !\n\n");
		printf("Réponse:");	scanf("%s", langue);
		system("clear");
	}
	sleep(1);
	system("clear");

	
	return atoi(langue);
}

int ChoixUtilisateur(int langue){
	char *utilisateur = NULL;
	utilisateur = (char*)malloc(100*sizeof(char));
	
	
	if(langue==1){
			char a[50]="\t\t\t       _   _ _ _           _                  ";
	char b[50]="\t\t\t _   _| |_(_) (_)___  __ _| |_ ___ _   _ _ __ ";
	char c[50]="\t\t\t| | | | __| | | / __|/ _` | __/ _ | | | | '__|";
	char d[50]="\t\t\t| |_| | |_| | | |__ | (_| | ||  __/ |_| | |  ";
	char e[50]=" \t\t\t|__,_||__|_|_|_|___/|__,_||__|___||__,_|_|  ";
	
	printf("%s\n%s\n%s\n%s\n%s\n\n",a,b,c,d,e);
		system("mpg123 -q /usr/share/sounds/pharmagest/Adorclfr.mp3 &");
		printf("\t\t");//Êtes vous un Administrateur ou un Client ?\n1-Administrateur \t2-Client \t3-Précédent\n");
			char lange[100]="Etes vous un Administrateur ou un Client ?";
		for(int i=0;i<strlen(lange);i++){
		printf("%c", lange[i] );
		usleep(60000);
		fflush(stdout);
		}
		printf("\n1-Administrateur \t2-Client \t3-Précédent\n");
		printf("==>Réponse: "); scanf("%s", utilisateur);
		system("clear");
		
		while(testa1(utilisateur) == 0)//GESTION ERREURS
		{												
						char a[50]="\t\t\t       _   _ _ _           _                  ";
	char b[50]="\t\t\t _   _| |_(_) (_)___  __ _| |_ ___ _   _ _ __ ";
	char c[50]="\t\t\t| | | | __| | | / __|/ _` | __/ _ | | | | '__|";
	char d[50]="\t\t\t| |_| | |_| | | |__ | (_| | ||  __/ |_| | |  ";
	char e[50]=" \t\t\t|__,_||__|_|_|_|___/|__,_||__|___||__,_|_|  ";
	
	printf("%s\n%s\n%s\n%s\n%s\n\n",a,b,c,d,e);	
			system("mpg123 -q /usr/share/sounds/pharmagest/Adorclfr.mp3 &");
			printf("Êtes vous un Administrateur ou un Client ?\n1-Administrateur \t2-Client \t3-Précédent\n");  
			printf("Réponse: "); scanf("%s", utilisateur);
			system("clear");
		}
		
		while(getchar() != '\n' && getchar() != EOF);
	}
	
	if(langue==2){
		char w[50]="\t\t\t _   _ ___  ___ _ __ ";
		char x[50]="\t\t\t| | | / __|/ _ | '__|";
		char j[50]="\t\t\t| |_| |__ |  __/ |   ";
		char m[50]="\t\t\t |__,_|___/|___|_| ";
	printf("%s\n%s\n%s\n%s\n\n",w,x,j,m);
		system("mpg123 -q /usr/share/sounds/pharmagest/Adorclien.mp3 &");
		printf("\t\t");//"Are you an Administrator or a Customer ?\n1-Administrator \t2-Customer \t3-Previous\n");
		char lan[100]="Are you an Administrator or a Customer ?";
		for(int i=0;i<strlen(lan);i++){
		printf("%c", lan[i] );
		usleep(60000);
		fflush(stdout);
		}
		printf("\n1-Administrator \t2-Customer \t3-Previous\n");
		printf("==>Answer: "); scanf("%s", utilisateur);
		system("clear");
		
		while(testa1(utilisateur) == 0){//GESTION ERREURS
			system("mpg123 -q /usr/share/sounds/pharmagest/Adorclien.mp3 &");
			printf("\t\t");		system("figlet user");
			printf("Are you an Administrator or a Customer ?\n1-Administrator \t2-Customer \t3-Previous\n");
			printf("==>Answer: "); scanf("%s", utilisateur);
			system("clear");			
		}
		
		while(getchar() != '\n' && getchar() != EOF);
	}

	sleep(0.5);
	system("clear");
	return atoi(utilisateur);
}

int login(int langue , int utilisateur){
	
	//-------------------------ADMNISTRATEUR FRANCAIS AVEC AUDIO-------------------//
	
	if(utilisateur==1 && langue==1)
	{
		int test = 3;
		int qlq = 3;
		char ida[10]="Brice";
		char id[50];
		char password[50]="pharmacie";
		char mdp[50];
		a:
		system("mpg123 -q /usr/share/sounds/pharmagest/idfr.mp3 &");
		system("figlet Connexion");
		
		printf("\n\t\tDonnez votre ID:"); scanf("%s", id );
		system("mpg123 -q /usr/share/sounds/pharmagest/passwdfr.mp3 &");
		printf("\n\t\tDonnez votre mot de passe:"); scanf("%s", mdp);
		
		sleep(2);
		system("clear");
		test=strcmp(mdp , password);
		qlq=strcmp(id , ida);
			if(test==0 && qlq==0){
				system("figlet administrateur");
				system("mpg123 -q /usr/share/sounds/pharmagest/Bricefr.mp3 &");
				printf("\t\tBienvenue %s .\nVous êtes connectés en tant qu'administrateur.\n", id);
				sleep(3);
			}
			char *try=NULL;
			try = (char*)malloc(100*sizeof(char));
			while(test !=0 || qlq !=0){
				if(test !=0 && qlq ==0){
					//char *try;
					//try = malloc(100*sizeof(char));
					char a[50]="\t\t  ___ _ __ _ __ ___  _ __ ";
					char b[50]="\t\t / _ | '__| '__/ _ || '__|";
					char c[50]="\t\t|  __/ |  | | | (_) | | ";
					char d[50]=" \t\t|___|_|  |_|  |___||_| ";
					printf("%s\n%s\n%s\n%s\n",a,b,c,d);
					system("mpg123 -q /usr/share/sounds/pharmagest/incorrectfr.mp3 &");
					printf("\n\tMOT DE PASSE INCORRECT\n");
					sleep(2.5);
				}
				if(test ==0 && qlq !=0){
					system("figlet erreur");
					system("mpg123 -q /usr/share/sounds/pharmagest/erroridfr.mp3 &");
					printf("\n\tIDENTIFIANT INCORRECT\n");
					sleep(3);
				}
				else if(test !=0 && qlq !=0){
					system("figlet erreur");
					system("mpg123 -q /usr/share/sounds/pharmagest/idetmdpfr.mp3 &");
					printf("\n\tIDENTIFIANT ET MOT DE PASSE INCORRECT\n");
					sleep(3);
				}
				system("mpg123 -q /usr/share/sounds/pharmagest/retryfr.mp3 &");
				printf("\t\tVoulez-vous réessayer ?\n1-OUI\t2-NON\n");
				printf("==>Réponse:");scanf("%s",try);
				system("clear");
				//GESTION ERREURS
				while(testa1(try) == 0){
					system("figlet Erreur");
					system("mpg123 -q /usr/share/sounds/pharmagest/retryfr.mp3 &");
					printf("\t\tVoulez-vous réessayer ?\n1-OUI\t2-NON\n");
					printf("==>Réponse:");scanf("%s" , try);
					system("clear");
				}
				
				sleep(1);
				system("clear");
				if(atoi(try)==1){
					goto a;	
					sleep(1);
					system("clear");
				}
				else if(atoi(try)==2){
					return 1;
					break;
				}
		}
	}

	//--------------------------------ADMINISTRATOR ANGLAIS AVEC AUDIO---------------------//
		if(utilisateur==1 && langue==2)
	{
		int test;
		int qlq;
		char ida[10]="Brice";
		char id[50];
		char password[50]="pharmacie";
		char mdp[50];
		c:
		system("figlet Login");
		system("mpg123 -q /usr/share/sounds/pharmagest/IDen.mp3 &");
		printf("\n\t\tGive your ID:"); scanf("%s", id );
		
		system("mpg123 -q /usr/share/sounds/pharmagest/passwden.mp3 &");
		printf("\n\t\tGive your password:"); scanf("%s", mdp);
		sleep(2);
		system("clear");
		test=strcmp(mdp, password);
		qlq=strcmp(ida,id);
			if(test==0 && qlq==0){
				system("figlet administrator");
				system("mpg123 -q /usr/share/sounds/pharmagest/Briceen.mp3 &");
				printf("Welcome %s .\nYou are connected in as administrator.\n", id);
				sleep(3);
			}
			char *try = NULL;
				try = calloc(100,sizeof(char));
			while(test !=0 || qlq !=0){
				if(test !=0 && qlq==0){
		char a1[50]="\t\t  ___ _ __ _ __ ___  _ __ ";
		char b1[50]="\t\t / _ | '__| '__/ _ || '__|";
		char c1[50]="\t\t|  __/ |  | | | (_) | | ";
		char d1[50]="\t\t |___|_|  |_|  |___||_| ";
		printf("%s\n%s\n%s\n%s\n",a1,b1,c1,d1);
					system("mpg123 -q /usr/share/sounds/pharmagest/incorrecten.mp3 &");
					printf("\n\tINVALID PASSWORD \n");
					sleep(2.5);
				}
				if(test ==0 && qlq !=0){
		char a[50]="\t\t  ___ _ __ _ __ ___  _ __ ";
		char b[50]="\t\t / _ | '__| '__/ _ || '__|";
		char c[50]="\t\t|  __/ |  | | | (_) | | ";
		char d[50]="\t\t |___|_|  |_|  |___||_| ";
		printf("%s\n%s\n%s\n%s\n",a,b,c,d);
					system("mpg123 -q /usr/share/sounds/pharmagest/erroriden.mp3 &");
					printf("\n\tINVALID IDENTIFIANT\n");
					sleep(3);
				}
				else if(test !=0 && qlq !=0){
					system("mpg123 -q /usr/share/sounds/pharmagest/idetmdpEn.mp3 &");
		char a[50]="\t\t  ___ _ __ _ __ ___  _ __ ";
		char b[50]="\t\t / _ | '__| '__/ _ || '__|";
		char c[50]="\t\t|  __/ |  | | | (_) | | ";
		char d[50]="\t\t |___|_|  |_|  |___||_| ";
					printf("%s\n%s\n%s\n%s\n",a,b,c,d);
					printf("\n\tIDENTIFIANT AND PASSWORD INVALID\n");
					sleep(3.5);
				}
				system("mpg123 -q /usr/share/sounds/pharmagest/retryen.mp3 &");
				printf("Do you want to try again?\n1-YES\t2-NO\n");
				printf("==>Answer:");scanf("%s" , try);
				system("clear");
				//GETION ERREURS
				while(testa1(try) == 0){
					system("figlet error");
					system("mpg123 -q /usr/share/sounds/pharmagest/retryen.mp3 &");
					printf("Do you want to try again?\n1-YES\t2-NO\n");
					printf("==>Answer:");scanf("%s" , try);
					system("clear");
				}
				
				sleep(2);
				system("clear");
				
				if(atoi(try)==1){
					goto c;	
					sleep(2);
					system("clear");
				}
				else if(atoi(try)==2){
					return 1;
					break;
				}
		}
		
	}
	
		sleep(2);
		system("clear");
	

	return 0;
}
//-------------------PASSANT AU CLIENT MAINTENANT-----------//
int job(int utilisateur,int langue){
	if(utilisateur==2)
	{
		if(langue==1){
			system("/usr/share/sounds/pharmagest/facturefr.sh");//Facture en français
		}
		if(langue == 2){	
		system("/usr/share/sounds/pharmagest/factureEn.sh");//Facture en anglais
		}
	}

	
	char *faire = NULL;
	faire = malloc(100*sizeof(char));
	
	if(utilisateur==1){
		if(langue ==1){
			system("figlet administrateur");
			system("mpg123 -q /usr/share/sounds/pharmagest/Menuadminfr.mp3 &");
			printf("\n\nQue voulez vous faire:\n\t1-Ajouter des médicaments\n\t2-Voir le stock disponible\n\t3-Enlever les médicaments épuisés\n\t4-Précédent\n");
			printf("==>Réponse: "); scanf("%s", faire);
			sleep(2);
			//GESTION ERREURS
			while(testa2(faire) == 0){
				system("clear");
				system("figlet administrateur");
				system("mpg123 -q /usr/share/sounds/pharmagest/Menuadminfr.mp3 &");
				printf("\n\nQue voulez vous faire:\n\t1-Ajouter des médicaments\n\t2-Voir le stock disponible\n\t3-Enlever les médicaments épuisés\n\t4-Précédent\n");
				printf("Réponse: "); scanf("%s", faire);
			}
		}
		
		if(langue==2){
			system("figlet administrator");
			system("mpg123 -q /usr/share/sounds/pharmagest/Adminmenuen.mp3 &");
			printf("\n\nWhat do you want to do:\n\t1-Add drugs\n\t2-See available stocks\n\t3-Remove spent medication\n\t4-Previous\n");
			printf("==>Answer:"); scanf("%s", faire);
			system("clear");
			
			//GESTION ERREURS
			while(testa2(faire) == 0){
				system("clear");
				system("figlet administrator");
				system("mpg123 -q /usr/share/sounds/pharmagest/Adminmenuen.mp3 &");
				printf("\n\nWhat do you want to do:\n\t1-Add drugs\n\t2-See available stocks\n\t3-Remove spent medication\n\t4-Previous\n");
				printf("==>Answer:"); scanf("%s", faire);
			}		
		}
	}
	return atoi(faire);
}

void ajout(int faire, int utilisateur, int langue){
	 ///ajout à la base de données///
	if(utilisateur==1 && faire ==1 && langue ==1){
	char append[255]="";
	char nomMedoc[50]="";
	char *price = NULL;
	price = malloc(100*sizeof(char));

	char *quantity = NULL;
	quantity = malloc(100*sizeof(char));
	
	char  *number = NULL;
	number = malloc(100*sizeof(char));
	system("figlet administrateur");
	system("mpg123 -q /usr/share/sounds/pharmagest/combienaddfr.mp3 &");
	printf("\t\tCombien de médicament allez vous ajouter: ");
	scanf("%s", number);
	system("clear");
	//GESTION ERREURS
	while(testa(number) == 0){
		system("figlet administrateur");
		system("mpg123 -q /usr/share/sounds/pharmagest/combienaddfr.mp3 &");
		printf("\t\tCombien de médicament allez vous ajouter: ");
		scanf("%s", number);
		system("clear");
	}
	
	for(int j=0;j<atoi(number);j++){
		while(getchar() != '\n' && getchar() != EOF);
		system("mpg123 -q /usr/share/sounds/pharmagest/Nommedfr.mp3 &");
		system("figlet administrateur");
		printf("\t\tNom du médicament:");
		fgets(nomMedoc,50,stdin);
		nomMedoc[strlen(nomMedoc)-1] = '\0';
		for(int i=0;i<strlen(nomMedoc);i++){
			nomMedoc[i]=tolower(nomMedoc[i]);
		}
		system("mpg123 -q /usr/share/sounds/pharmagest/prixunifr.mp3 &");
		printf("\t\tPrix unitaire:");
		scanf("%s", price);
		
		//GESTION ERREURS
		while(testa(price) == 0){
			system("mpg123 -q /usr/share/sounds/pharmagest/prixunifr.mp3 &");
			printf("\t\tPrix unitaire:");
			scanf("%s", price);
			system("clear");
		}
		
		system("mpg123 -q /usr/share/sounds/pharmagest/Qttaddfr.mp3 &");
		printf("\t\tQuantité à ajouter:");
		scanf("%s", quantity);
		
		while(testa(quantity) == 0){
			system("mpg123 -q /usr/share/sounds/pharmagest/Qttaddfr.mp3 &");
			printf("\t\tQuantité à ajouter:");
			scanf("%s", quantity);
			system("clear");
		}
		system("clear");
		sprintf(append,"echo 'NOM:%s;PRIX:%d;QUANTITE:%d' >> /usr/share/sounds/pharmagest/depotfr",nomMedoc, atoi(price),atoi(quantity));
		system(append);
		system("sort /usr/share/sounds/pharmagest/depotfr -b -k 1 -o /usr/share/sounds/pharmagest/depotfr");
		strcpy(append , "");
		sprintf(append,"echo 'NAME:%s;PRICE:%d;QUANTITY:%d' >> /usr/share/sounds/pharmagest/depoteng",nomMedoc,atoi(price),atoi(quantity));
		system(append);
		system("sort /usr/share/sounds/pharmagest/depoteng -b -k 1 -o /usr/share/sounds/pharmagest/depoteng");
		}
	}
	else if(utilisateur==1 && faire ==1 && langue ==2){
	char append[255]="";
	char nomMedoc[50]="";
	char *price = NULL;
	price = malloc(100*sizeof(char));

	char *quantity = NULL;
	quantity = malloc(100*sizeof(char));
	
	char *number = NULL;
	number = malloc(100*sizeof(char));
	system("figlet administrator");
	system("mpg123 -q /usr/share/sounds/pharmagest/combienadden.mp3 &");
	printf("\t\tHow many medication are you going to add: ");scanf("%s",number);
	system("clear");
	//GESTION ERREURS
	while(testa(number) == 0){
	system("figlet administrator");	
		system("mpg123 -q /usr/share/sounds/pharmagest/combienadden.mp3 &");
		printf("\t\tHow many medication are you going to add: ");scanf("%s",number);
		system("clear");
	}
	
	//while(getchar() != '\n' && getchar() != EOF);
	for(int j=0;j<atoi(number);j++){
		while(getchar() != '\n' && getchar() != EOF);
		system("mpg123 -q /usr/share/sounds/pharmagest/Nommeden.mp3 &");
		printf("\t\tName of the medication: ");
		fgets(nomMedoc,50,stdin);
		nomMedoc[strlen(nomMedoc)-1] = '\0';
		for(int i=0;i<strlen(nomMedoc);i++){
			nomMedoc[i]=tolower(nomMedoc[i]);
		}
		system("mpg123 -q /usr/share/sounds/pharmagest/prixunien.mp3 &");
		printf("\t\tUnit price:");
		scanf("%s", price);
		
		//GESTION ERREURS
		while(testa(price) == 0){
			system("mpg123 -q /usr/share/sounds/pharmagest/prixunien.mp3 &");
			printf("\t\tUnit price:");
			scanf("%s", price);
			system("clear");
		}
		system("mpg123 -q /usr/share/sounds/pharmagest/Qttadden.mp3 &");
		printf("\t\tQuantity to add:");
		scanf("%s", quantity);
		
		//GESTION ERREURS
		while(testa(quantity) == 0){
			system("mpg123 -q /usr/share/sounds/pharmagest/Qttadden.mp3 &");
			printf("\t\tQuantity to add:");
			scanf("%s", quantity);
			system("clear");			
		}
		system("clear");
		sprintf(append,"echo 'NAME:%s;PRICE:%d;QUANTITY:%d' >> /usr/share/sounds/pharmagest/depoteng",nomMedoc,atoi(price) , atoi(quantity));
		system(append);
		system("sort /usr/share/sounds/pharmagest/depoteng -b -k 1 -o /usr/share/sounds/pharmagest/depoteng");
		strcpy(append,"");
		sprintf(append,"echo 'NOM:%s;PRIX:%d;QUANTITE:%d' >> /usr/share/sounds/pharmagest/depotfr",nomMedoc,atoi(price), atoi(quantity));
		system(append);
		system("sort /usr/share/sounds/pharmagest/depotfr -b -k 1 -o /usr/share/sounds/pharmagest/depotfr");
		}
	}

//---------SUPPRIMMER DES BASES DE DONNÉES EN FRANÇAIS-------------//

	if(utilisateur==1 && faire ==3 && langue ==1){
		///supression dans la base de données
		char *number = NULL;
		number = malloc(100*sizeof(char));
		
		char aSupprimer[50]="";
		char delete[255]="";
		system("mpg123 -q /usr/share/sounds/pharmagest/combsupprfr.mp3 &");
		printf("\t\tCombien de médicament allez vous supprimer: ");scanf("%s",number);
		while(testa(number) == 0){
			system("mpg123 -q /usr/share/sounds/pharmagest/combsupprfr.mp3 &");
			printf("\t\tCombien de médicament allez vous supprimer: ");scanf("%s",number);
			system("clear");
		}
		for(int j=0;j<atoi(number);j++){
			while(getchar() != '\n' && getchar() != EOF);
			system("mpg123 -q /usr/share/sounds/pharmagest/medsupprfr.mp3 &");
			printf("\t\tNom du médicament: ");
			fgets(aSupprimer,50,stdin);
			aSupprimer[strlen(aSupprimer)-1] = '\0';
			for(int i=0;i<strlen(aSupprimer);i++){
				aSupprimer[i]=tolower(aSupprimer[i]);
			}
		}
		sprintf(delete,"grep -vi \"%s\" /usr/share/sounds/pharmagest/depotfr > /usr/share/sounds/pharmagest/tmp ; cat /usr/share/sounds/pharmagest/tmp > /usr/share/sounds/pharmagest/depotfr ; rm /usr/share/sounds/pharmagest/tmp",aSupprimer);
		system(delete);
		strcpy(delete,"");
		sprintf(delete,"grep -vi \"%s\" /usr/share/sounds/pharmagest/depoten > /usr/share/sounds/pharmagest/tmp ; cat /usr/share/sounds/pharmagest/tmp > /usr/share/sounds/pharmagest/depoten ; rm /usr/share/sounds/pharmagest/tmp",aSupprimer);
		system(delete);
	}
	//------SUPPRIMER DES BASES DE DONNÉES EN ANGLAIS--------//

	else if(utilisateur==1 && faire == 3 && langue ==2){
		
		char *number = NULL;
		number = malloc(100*sizeof(char));
		
		char aSupprimer[50]="";
		char delete[255]="";
		system("mpg123 -q /usr/share/sounds/pharmagest/combsuppren.mp3 &");
		printf("\t\tHow many medication are you going to delete: ");scanf("%s", number);
		//GESTION ERREURS
		while(testa(number) == 0){
			system("mpg123 -q /usr/share/sounds/pharmagest/combsuppren.mp3 &");
			printf("\t\tHow many medication are you going to delete: ");scanf("%s", number);
			system("clear");
		}
		for(int j=0;j<atoi(number);j++){
			while(getchar() != '\n' && getchar() != EOF);
			system("mpg123 -q /usr/share/sounds/pharmagest/medsuppren.mp3 &");
			printf("\t\tName of the medication: ");
			fgets(aSupprimer,50,stdin);
			aSupprimer[strlen(aSupprimer)-1] = '\0';
			for(int i=0;i<strlen(aSupprimer);i++){
				aSupprimer[i]=tolower(aSupprimer[i]);
			}
		}
		sprintf(delete,"grep -vi \"%s\" /usr/share/sounds/pharmagest/depoteng > /usr/share/sounds/pharmagest/tmp ; cat /usr/share/sounds/pharmagest/tmp > /usr/share/sounds/pharmagest/depoteng ; rm /usr/share/sounds/pharmagest/tmp",aSupprimer);
		system(delete);
		strcpy(delete , "");
		sprintf(delete,"grep -vi \"%s\" /usr/share/sounds/pharmagest/depotfr > /usr/share/sounds/pharmagest/tmp ; cat /usr/share/sounds/pharmagest/tmp > /usr/share/sounds/pharmagest/depotfr ; rm /usr/share/sounds/pharmagest/tmp",aSupprimer);
		system(delete);
	}
		
	//--------VOIR LES STOCKS DE L'ADMINSTRATEUR------------//	
		if(utilisateur==1 && faire == 2 && langue == 1){
			system("cat /usr/share/sounds/pharmagest/depotfr | cut -f 1,3 -d \"	\" | less");
		}
		if(utilisateur==1 && faire ==2 && langue ==2){
			system("cat /usr/share/sounds/pharmagest/depoteng | cut -f 1,3 -d \"	\" | less");
		}
}



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

