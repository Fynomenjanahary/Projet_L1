char** SepareeMot(char*mot,char ch){
	char **MotSeparee=Allouer2D(100);
	int k=0,j=0;
	for(int i=0; i<strlen(mot); i++){
		if(mot[i]==ch){
			k++;j=0;
		}
		else {
			MotSeparee[k][j] = mot[i];
			j++;
		}
	}
	return MotSeparee;
}

