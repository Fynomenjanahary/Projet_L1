int count_line(int count , FILE *file){
	
	while (! feof (file)){
			if(fgetc(file) == '\n'){
				count++;
			}
	}
	
	return count;
}

Etudiant* taking(FILE* file , int count){
	char line[1000];
	Etudiant *Info = malloc(sizeof(Etudiant)*count);
	for(int i=0;fgets(line,1000,file) != NULL;i++){
		sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",Info[i].nom,Info[i].prenom,Info[i].tel,Info[i].mail,Info[i].adresse,Info[i].date,Info[i].lieu,Info[i].anne,Info[i].genre,Info[i].cin,Info[i].url);
	}
	return Info;
}

Etudiant* triage(Etudiant* Info , int count){
	for(int i=1 ; i<count ; i++){
		for(int j=i+1 ; j<count ; j++){
			if(strcmp(Info[i].nom,Info[j].nom)>1){
				char tmp[300];
				strcpy(tmp , Info[j].nom);strcpy(Info[j].nom , Info[i].nom);strcpy(Info[i].nom , tmp);
				strcpy(tmp , Info[j].prenom);strcpy(Info[j].prenom , Info[i].prenom);strcpy(Info[i].prenom , tmp);
				strcpy(tmp , Info[j].tel);strcpy(Info[j].tel , Info[i].tel);strcpy(Info[i].tel , tmp);
				strcpy(tmp , Info[j].mail);strcpy(Info[j].mail , Info[i].mail);strcpy(Info[i].mail , tmp);
				strcpy(tmp , Info[j].adresse);strcpy(Info[j].adresse , Info[i].adresse);strcpy(Info[i].adresse , tmp);
				strcpy(tmp , Info[j].date);strcpy(Info[j].date , Info[i].date);strcpy(Info[i].date , tmp);
				strcpy(tmp , Info[j].lieu);strcpy(Info[j].lieu , Info[i].lieu);strcpy(Info[i].lieu , tmp);
				strcpy(tmp , Info[j].anne);strcpy(Info[j].anne , Info[i].anne);strcpy(Info[i].anne , tmp);
				strcpy(tmp , Info[j].genre);strcpy(Info[j].genre , Info[i].genre);strcpy(Info[i].genre , tmp);
				strcpy(tmp , Info[j].cin);strcpy(Info[j].cin , Info[i].cin);strcpy(Info[i].cin , tmp);
				strcpy(tmp , Info[j].url);strcpy(Info[j].url , Info[i].url);strcpy(Info[i].url , tmp);
			}
		}
	}
	
	return Info;
}

FILE* submit(Etudiant* Info , int count){
	FILE* trie = fopen("info_trie.csv","a+");
	
	for(int i=0;i<count;i++){
		fprintf(trie,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",Info[i].nom,Info[i].prenom,Info[i].tel,Info[i].mail,Info[i].adresse,Info[i].date,Info[i].lieu,Info[i].anne,Info[i].genre,Info[i].cin,Info[i].url);
	}
	
	
	return trie;
}
