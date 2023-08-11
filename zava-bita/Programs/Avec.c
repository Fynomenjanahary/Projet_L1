#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char ** allouerChar2D(int n,int m);
char **split(char separator, char *at);

int main(){
	char* string = malloc (50);
	string = "12.53/05.23/2023.23";
	double year=0;
	double mounth=0;
	double day=0;
	char separator='/';
	char** misaraka;
	misaraka = allouerChar2D(4,10);
	misaraka=split(separator , string);
	year=atof(misaraka[2]);
	mounth=atof(misaraka[1]);
	day=atof(misaraka[0]);
	
	
	return 0;
}

char ** allouerChar2D(int n,int m){
	char ** tmp;
	tmp = (char**)malloc(n*sizeof(char*));
	for(int i =0; i<n ;i++){
		tmp[i] = malloc(m);
	}
	return tmp;
}

char **split(char separator, char *at){
	char **splited=NULL;
	int j=0,k=0,count=0;
	for(int i=0;i<strlen(at);i++){
		if(at[i]==separator) count++;
	}
	splited=(char**)calloc(sizeof(char*),count+1);
	for(int i=0;i<count+1;i++){
		*(splited+i)=(char*)calloc(1,50);
	}
	for(int i=0;i<strlen(at);i++){
		if(at[i]==separator){
			k++;j=0;
		}
		else{
			*(*(splited+k)+j) = at[i];
			j++;
		}
	}
	return splited;
}

char* avadika(double year , double mounth , double day){
	double change=0;
	change=(year-(int)year)*12*365*24*3600;
	int var=(int)change;
	int seconde=var%60;
	int tmp=var/60;
	int minute=tmp%60;
	tmp=tmp/60;
	int heure=tmp%24;
	tmp=tmp/24;
	if((int)mounth==1 && (int)mounth==3 && (int)mounth==5 && (int)mounth==7 && (int)mounth==8 && (int)mounth==10 && (int)mounth==12){
		int jour=tmp%30;
		int mois=tmp/30;
	else if((int)mounth==4 && (int)mounth==6 && (int)mounth==9 && (int)mounth==11){
		int jour=tmp%31;
		int mois=tmp/31;
	else{
		if(year%4==0 && year%100!=0){
			int jour=tmp%29;
			int mois=tmp/29;
		} 
		else{
			int jour=tmp%28;
			int mois=tmp/28;
		}
	}
	mounth=mounth+mois;
	double change1=(mounth-(int)mounth)*24*3600;
	int var1=(int)change1;
	int seconde1=var1%60;
	int tmp1=var1/60;
	int minute1=tmp1%60;
	tmp1=tmp1/60;
	int heure1=tmp1%24;
	int jour1=tmp1/24;
	
	day=day+jour+jour1;
	double change2=(day-(int)day)*3600;
	int var2=(int)change2;
	int seconde2=var2%60;
	int minute2=var2/60;
	
	int minT=minute+minute2+minute1;
	int secT=seconde+seconde1+seconde2;
	int jourT=(int)day;
	if(jourT)
	
	return tab;
}
