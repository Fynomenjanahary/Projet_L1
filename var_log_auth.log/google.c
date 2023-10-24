/// #Mihantso3313

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lien.c"

int main() {
	
	printf("Content-Type: text/html\n\n");
	
	int link,nbr;
	char *string;
	char *nine = malloc(200);
    string = malloc(200);
    
    FILE *retour;
	retour = fopen("journal.csv","r");
	FILE *redi = fopen("redirect.txt","w");
    Lien *alaina = get(&nbr , string , &link , nine);
     char *tamy = malloc(200);
    strcpy(tamy , nine);
	strcat(nine,".txt");
	
	char *nomfichier = malloc(200);
	
	strcpy(nomfichier,"find /usr/lib/cgi-bin/ -name ");
	strcat(nomfichier,nine);
	//~ printf(" %s ioto\n",nomfichier);
	FILE *check = popen(nomfichier,"r");
	
	char vide[10];
	
	fgets(vide,10,check); 
	
    
	//~ printf("Content-type: text/html\n\n");
    //~ printf("Cache-Control: no-cache, no-store, must-revalidate\n");
    //~ printf("Pragma: no-cache\n");
    //~ printf("Expires: 0\n\n");
    
    
    printf("<head><meta charset=\"UTF-8\"><link rel=\"stylesheet\" href=\"=./recherche_user.css\"><title>Correspondance</title><style>body{min-height:100vh;background-color:#23292a;color:white;width:100vw;justify-content:center;}a{text-decoration:none;margin:15vw 1vw;min-width:11vw ;height:11vw;border:1px solid white;background:#aae2e6;color:black;border-radius:2vw;font-size: 2vw}th, td{border: 1px solid #000;padding: 10px;min-width:15vw;}h1{color:#000;font-size:3vw;text-shadow: 8px 1px 5px #640e83b5;}</style></head>");
    printf("<body style=\"text-align:center;\"><div style =\"width:70vw;background-color:#aeebeba8;border-radius: 8px;padding:10px 0px 10px 0px;margin-left:15%%;\"><table style=\"border-collapse: collapse;width: 300px;margin-bottom: 20px;margin-left: 130px;\">\n");
    printf("<div class=\"box\" style=\"margin-left:50vw;\">");
	printf("<span class=\"b\"></span>");
	printf("<form action=\"http://playlist.mg/cgi-bin/google.cgi\" method=\"get\">");
	printf("<h2>Search</h2>");
	printf("<div class=\"inputbox\">");
	printf("<input type=\"text\" required=\"required\" name=\"%s\">",tamy);
	printf("<span>Username</span>");
	printf("<i></i>");
	printf("</div>");
	printf("<input type=\"hidden\" name=\"lien\" value=\"1\">");
	printf("<input type=\"submit\" value=\"Data\">");
	printf("</form>");
    printf("</div>");
    
    //~ printf("%d anio \n",result);
    if(strcmp(vide,"") != 0){
		if(nbr == 0) printf("<h1>Aucune correspondance!!!</h1>\n");
		else{
			char liene[1000];
			if(link <=5){
				for(int i=1; i<=10 ; i++){
					if(i<nbr/10){
						sprintf(liene,"http://playlist.mg/cgi-bin/google.cgi?%s=%s&lien=%d",nine,string,i);
						printf("<a href=\"%s\">%d</a>\n",liene,i);
					}
				}
			}
			else{
				for(int i=link-4; i<=link+5 ; i++){
					if(i<nbr/10){
						sprintf(liene,"http://playlist.mg/cgi-bin/google.cgi?%s=%s&lien=%d",nine,string,i);
						printf("<a href=\"%s\">%d</a>\n",liene,i);
					}
				}
			}
			printf("<h1>L'utilisateur correspondant</h1>\n");
			printf("<thead><tr><th>TIME</th><th>OPENING/CLOSING</th><th>USER</th></tr></thead>\n");
			printf("<tbody>\n");
	
			int fifa = 10*(link-1);
			int mama=link*10,i=0;
			for(;i<nbr;i++)
			if(i>fifa && i<=mama){
				printf("<tr><th>%s</th><th>%s</th><th>%s</th></tr>\n", alaina[i].time,alaina[i].open,alaina[i].user);
			}
		
		
			printf("</tbody>\n");
			printf("</table>\n");
		
			
		
			printf("</div></body>\n");
		}
		
		printf("<a href=\"http://www.fifaliantsoa.com/cgi-bin/logout.cgi?zvt=%s\">Deconnexion</a>\n",nine);
		
		fclose(retour);
		fclose(redi);
	}
	
	else{
		printf("</head>");
		printf("<body style=\"display:flex;align-items:center;justify-content:center;\">"
			"<div style=\"width:30vw;height:20vw;border: 2px solid black ;box-shadow:0px 0px 20px 4px #3c302d;text-align:center;background-color:#464545cc;\">"
				"<h3>Vous n'avez ouvert aucune session !</h3><br>"
				"<h4>Veuillez vous connecter en appuiant sur </h4><br>"
				"<a href=\"http://www.fifaliantsoa.com/form.html\" style=\"text-decoration:none;padding:2px;border:2px solid black;color:black;\">Connexion</a>"
			
			"</div>"
		"</body>"
		);
	}
	return 0;
}
