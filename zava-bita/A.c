#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "chartodouble.c"
void variarespace(char* date,char**vari,int esp);
int estespace(char*date);
void PositionSlash(char**vari,int*slash);
void separslash(char**vari,char**car,int* slash);
void Positiontwopoint(char**vari,int*p);
void separtwopoint(char**vari,char**ca,int* p);
double charTodouble(char*chaine);
double convertjour(double j,double mo,double ans,double j1,double m,double ns);
int main(){
	
	char*date="16/07/2023 15/06/2023";
		int slash[2];
		
		int esp;
		int p[2] ;
		esp=0;
		 
		char**vari;
	vari=malloc(2);
	for(int j=0;j<2;j++){
		vari[j]=malloc(22);
	}
	esp=estespace(date);
	variarespace(date,vari,esp);
	printf("%s\n",vari[0]);
	printf("%s\n",vari[1]);
	PositionSlash(vari,slash);
	printf("%d\n",slash[0]);
	printf("%d\n",slash[1]);
	 char**car;
	 car=malloc(4);
	for(int j=0;j<4;j++){
		car[j]=malloc(22);
	}
	separslash(vari,car,slash);
	separslash(vari,car,slash);
	separslash(vari,car,slash);
	printf("car[0]%s\n",car[0]);
	printf("car[1]%s\n",car[1]);
	printf("car[2]%s\n",car[2]);
	Positiontwopoint(vari,p);
	printf("%d\n",p[0]);
	printf("%d\n",p[1]);
	char**ca;
	 ca=malloc(4);
	for(int j=0;j<4;j++){
		ca[j]=malloc(45);
	}
	separtwopoint(vari,ca, p);
		printf("ca[0]%s\n",ca[0]);
	    printf("ca[1]%s\n",ca[1]);
	    printf("ca[2]%s\n",ca[2]);  
	    
	    
	
	/*double j=charTodouble(*car);
	double mo=charTodouble(*(car+1));
	double ans=charTodouble(*(car+2));
	 double j1=charTodouble(*ca);
	
	 double m= charTodouble(*(ca+1));
	 double ns=charTodouble(*(ca+2));*/
	 double j=resultat(car);
	 double mo=resultat((car+1));
	 double ans=resultat((car+2));
	 double j1=resultat(ca);
	 double m=resultat((ca+1));
	 double ns=resultat((ca+2));
	
	 
	
	   double daty;
	   
	   daty=convertjour(j,mo,ans,j1,m,ns);
	   printf("date finale :%f\n",daty);
	return 0;
}
int estespace(char*date){
    	int val=0;
	   for(int i=0;i<strlen(date);i++){
 		  if(date[i]==' ')
 			 return i;
	}
    	return val;
}
void variarespace(char* date,char**vari,int esp){
	 
       
	for(int i=0;i<esp;i++)
		vari[0][i]=date[i];
	
	for(int j=esp+1,i=0;j<strlen(date);i++,j++)
		vari[1][i]=date[j];
	
 return ;
}
void PositionSlash(char**vari,int*slash){
    for(int i=0;i<strlen(*vari);i++)
        if(*(*(vari)+i)=='/'){
			slash[0]=i;
			break;
        }
     
    for(int j=(*slash+1);j<strlen(*vari);j++)
       if(*(*(vari)+j)=='/'){
		   slash[1]=j;
		   break;
	   }
    
    return ;
 }
 void separslash(char**vari,char**car,int* slash){
	int x=0,y=0;
    for(int i=0;i<strlen(*vari);i++){
		if(*(*(vari)+i)=='/'){
			x++,y=0,i++;
		}
		car[x][y]=*(*(vari)+i);
		y++;
	}
} 
void Positiontwopoint(char**vari,int*p){
    for(int i=0;i<strlen(*(vari+1));i++)
        if(*(*(vari+1)+i)=='/'){
			p[0]=i;
			break;
        }
     
    for(int j=(*p+1);j<strlen(*(vari+1));j++)
       if(*(*(vari+1)+j)=='/'){
		   p[1]=j;
		   break;
	   }
    
    return ;
 }
  void separtwopoint(char**vari,char**ca,int* p){
	int x=0,y=0;
    for(int i=0;i<=strlen((*vari+1));i++){
		if(*(*(vari+1)+i)=='/'){
			x++,y=0,i++;
		}
		ca[x][y]=*(*(vari+1)+i);
		y++;
	}
}


double convertjour(double j,double mo,double ans,double j1,double m,double ns){
	
	
	int jfil,jfil2;
	double div;
	div=0.0;
	jfil=(int)j+((int)mo*31)+((int)ans*365);
	jfil2=(int)j1+((int)m*31)+((int)ns*365);
	div=jfil/jfil2;
	//printf("%f",div);
	return div;
}	
