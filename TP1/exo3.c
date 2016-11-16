#include <stdio.h>

int lirenp(){
	int entier=0;
	int max=0;
	int min=0;
	FILE *ficr;
	FILE *ficp;
	FILE *ficn;
	ficr=fopen("releves.txt","r");
	ficn=fopen("negatif.txt","w");
	ficp=fopen("positif.txt","w");
	
	fscanf(ficr,"%i",&entier);
	while(!feof(ficr)){
		if(max<entier){
			max=entier;
		}
		if(min>entier){
			min=entier;		
		}
		if (entier>=0){
			fprintf(ficp,"%i ",entier);
		}
		if(entier<0){
			fprintf(ficn,"%i ",entier);		
		}
		fscanf(ficr,"%i",&entier);
	}
	printf("le max est : %i le min est :%i \n",max,min);	

	fclose(ficr);
	fclose(ficn);
	fclose(ficp);
}


int main(){
	lirenp();
}