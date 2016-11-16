
#include <stdio.h>

int affichecle(){

	char nom[20];	
	FILE *fic;
	char n;
	int n_espace=0;
	int n_ligne=0;
	int n_carac=0;	
	printf("donner le nom du ficher: ");

	scanf("%s",nom);

	fic=fopen(nom,"r");

	if(fic==NULL){
		printf("Ce fichier n'existe pas");
	 }
	else{
		fscanf(fic,"%c",&n);
		while(!feof(fic)){
			if(n==' '){
				n_espace++;
			}
			else if(n=='\n'){
				n_ligne++;
				n_espace++;
			}
			else{
				n_carac++;
			}
			
			fscanf(fic,"%c",&n);
		}
		n_espace++;
		n_ligne++;
		printf("caractères: %i , mots: %i , ligne: %i",n_carac,n_espace,n_ligne);
		fclose(fic);
	}
	
}

int main(){
	affichecle();
}