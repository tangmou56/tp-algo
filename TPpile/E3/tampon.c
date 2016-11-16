#include"file.h"



void main(){
	int entier;
	int n;
	int tete1;
	int queue1;
	printf("Donnez un nombre: ");
	scanf("%i",&entier);
	while(entier!=-1){
		
		if(entier==0){
			
			printf("Nombre lus: ");
			retirer(&n);
			get(&tete1,&queue1);
			while(tete1!=queue1){
				printf("%i ",n);
				retirer(&n);
				get(&tete1,&queue1);
				
			}	
			printf("%i \n",n);
		}
		else{
			ajouter(entier);		
		}
	printf("Donnez un nombre: ");
	scanf("%i",&entier);
	}
	printf("Au revoir!\n");
}