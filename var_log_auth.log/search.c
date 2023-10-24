#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	printf("Content-Type: text/html\n\n");
	
	printf("<!DOCTYPE html><html lang='en'>");
	
	char *query_string = getenv("QUERY_STRING");
	char user[20],name[20];
	sscanf(query_string,"%*[^=]=%[^\n]",user);
	strcpy(name , user);
	strcat(user,".txt");
	
	printf("<head>");
	printf("	<meta charset='UTF-8'>");
	printf("    <meta http-equiv='X-UA-Compatible' content='IE=edge'>");
	printf("    <meta name='viewport' content='width=device-width, initial-scale=1.0'>");
	
	FILE *file = fopen("redirect.txt","r");
	char tmp[20];
	FILE *check = fopen(user,"r");
	if(check == NULL){
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
	
	else{
		if(fgets(tmp,19,file)==NULL){
			printf("	<meta http-equiv='refresh' content='0;url=http://www.fifaliantsoa.com/form.html'>");
		}
		
		
		else{
			
		
		printf("<style>");
		printf("*{"
			"margin:0;"
			"padding:0;"
			"box-sizing: border-box;"
			"font-family: face;}"
		);
		
		printf("@font-face{"
			"font-family:face;"
			"src:(\"./css/fonts/montserrat/MontserratAlternates-Medium.otf\");}"
		);
		
		printf("body{"
			"display:flex;"
			"justify-content:center;"
			"align-items:center;"
			"min-height:100vh;"
			"background-color:#23242a;}"
		);
		
		printf(".box{"
			"position:relative;"
			"width: 380px;"
			"height:250px;"
			"background: #1c1c1c;"
			"border-radius: 8px;"
			"overflow:hidden;}"
		);
		
		printf(".box::before{"
			"content: \"\";"
			"position: absolute;"
			"top:-50%%;"
			"left:-50%%;"
			"width: 380px;"
			"height:250px;"
			"background: linear-gradient(0deg,transparent,transparent,#45f3ff,#45f3ff,#45f3ff);"
			"z-index:1;"
			"transform-origin:bottom right;"
			"overflow:hidden;"
			"animation: miodina 6s linear infinite;}"
		);
		
		printf("@keyframes miodina{"
			"from{"
				"transform: rotate(0deg);"
			"}"
			"to{"
				"transform: rotate(360deg);"
			"}"
			"}"
		);
		
		printf(".box::after{"
		"content: \"\";"
		"position: absolute;"
		"top:-50%%;"
		"left:-50%%;"
		"width: 380px;"
		"height:250px;"
		"background: linear-gradient(0deg,transparent,transparent,#ff06ac,#ff06ac,#ff06ac);"
		"z-index:1;"
		"transform-origin:bottom right;"
		"overflow:hidden;"
		"animation: anime 6s linear infinite;"
		"animation-delay: 3s;}"
		);
		
		printf("@keyframes anime{"
		"from{"
			"transform: rotate(0deg);"
		"}"
		"to{"
			"transform: rotate(360deg);"
		"}}"
		);
		
		printf(".box form{"
		"position:absolute;"
		"inset:4px;"
		"background:#222;"
		"padding:50px 40px;"
		"border-radius:8px;"
		"z-index:2;"
		"display:flex;"
		"flex-direction: column;}"
);	
		
		printf("h2{"
		"color: #fff;"
		"font-weight:500;"
		"text-align: center;"
		"letter-spacing: 0.1em;"
"}"	
	
".in	putbox{"
		"position:relative;"
		"width:300px;"
		"margin-top:15px;"
"}"	
);	
		
		printf(".box form .inputbox input{"
		"position:relative;"
		"width:100%%;"
		"padding: 20px 10px 10px ;"
		"background:transparent;"
		"outline: none;"
		"border:none;"
		"box-shadow:none;"
		"color: #23242a;"
		"letter-spacing:0.05em;"
		"transition:0.5s;"
		"z-index:10;"
"}"	
);	
	
		printf(".box form .inputbox span{"
		"position:relative;"
		"right:-10Opx;"
		"top:0;"
		"padding:20px 0px 10px;"
		"pointer-events:none;"
		"color:#8f8f8f;"
		"font-size:1em;"
		"letter-spacing:0.05em;"
		/*transition:0.5s;*/
"}"	
		);
		
		printf(".box form .inputbox input:focus~span,"
		".box form .inputbox input:valid~span{"
		"position:absolute;"
		"color: #fff;"
		"font-size:0.75em;"
		"transform: translate(-300px,-34px);"
		"}"
);	
		
		printf(".box form .inputbox i{"
		"position: absolute;"
		"left: 0;"
		"bottom:0;"
		"width:100%%;"
		"height: 2px;"
		"background: #fff;"
		"border-radius: 4px;"
		"overflow:hidden;"
		"transition:0.5s;"
		"pointer-events:none;"
		"}"
	
		".box form .inputbox input:focus~i,"
		".box form .inputbox input:valid~i{"
		"height:44px;"
		"}"
		);
		
		printf(".box form input[type=\"submit\"]{"
		"border:none;"
		"outline:none;"
		"padding:9px 25px;"
		"background:#fff;"
		"cursor:pointer;"
		"font-size:0.9em;"
		"border-radius:4px;"
		"font-weight: 600;"
		"width:100px;"
		"margin-top:10px;"
"}"	
	
			".box form input[type=\"submit\"]:active{"
			"opacity:0;"
			"}"
		);
		
		printf("</style>");
		
		printf("    <title>Recherche User</title>");
		printf("    <link rel='stylesheet' type='text/css' href='style.css'>");
		printf("</head>");
		
		printf("<body>");
		printf("	<div class='box'>");
		printf("		<span class='b'></span>");
		printf("		<form action='http://playlist.mg/cgi-bin/google.cgi' method='get'>");
		printf("			<h2>Search</h2>");
		printf("			<div class='inputbox'>");
		printf("				<input type='text' required='required' name='%s'>",name);
		printf("				<span>Username</span>");
		printf("				<i></i>");
		printf("			</div>");
		printf("			<input type='hidden' name='lien' value='1'>");
		printf("			<input type='submit' value='Data'>");
		printf("		</form>");
		printf("    </div>");
		printf("</body>");
		printf("</html>");
		}
	}
	
	return 0;
	
}
