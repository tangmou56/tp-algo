#include<stdio.h>
#define N 50
void affiche(int *tab,int n){
	for(int i=0;i<=n;i++){
		printf("%i ",tab[i]);
	}
	printf("\n");
}





void tri_selec(int *tab,int i){
	int tabs[N];
	int m,im;
	for(int j=0;j<=i;j++){
		tabs[j]=tab[j];
	}
	int min=1000;
	for(int y=0;y<=i;y++){
		for(int x=y;x<=i;x++){
			if(tabs[x]<=min){
				min=tabs[x];
				im=x;
			}
		}
		
		m=tabs[y];
		tabs[y]=min;
		tabs[im]=m;
		min=1000;
	}
	affiche(tabs,i);

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
			tri_selec(tab,i);
			
		}
	}
}