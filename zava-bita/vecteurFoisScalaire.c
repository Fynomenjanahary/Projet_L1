int* remplissage(int* vect){
	vect = malloc(3*sizeof(int));
	printf("entrez le vecteur : ");
	for(int i=0 ; i<3 ; i++){
		scanf("%d",vect+i);
	}
	int lamda=0;
	printf("entrez le scalaire : ");
	scanf("%d",&lamda);
	for(int i=0 ; i<3 ; i++){
		vect[i]=vect[i]*lamda;
	}

	return vect;
}
