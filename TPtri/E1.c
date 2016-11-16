#include<stdio.h>
#define N 50

void tri_inser(int *tab,int i){
	int max=0;
	for(int j=0;j<i;j++){
		if(tab[i]<tab[j]){
			for(int x=i;x>=j;x--){
				tab[x+1]=tab[x];
			}
			tab[j]=tab[i+1];
		}
	}


}

void affiche(int *tab,int n){
	for(int i=0;i<=n;i++){
		printf("%i ",tab[i]);
	}
	printf("\n");
}



int main(){
	int entier;
	int tab[N];
	for(int i=0;i<N;i++){
		scanf("%i",&entier);
		if(entier==-1){
			i=N;	
		}
		else{
			tab[i]=entier;
			tri_inser(tab,i);
			affiche(tab,i);
		}
	}
}