#include"file.h"
int tete=0;
int queue=0;
int file[N];

void ajouter(int n){
	file[queue]=n;
	queue++;
	if(queue>=N){
		queue=0;
	}
}

void retirer(int* n){
	*n=file[tete];
	tete++;
	if(tete>=N){
		tete=0;
	}
}

void get(int *a,int *b){
	*a=tete;
	*b=queue;
	
}