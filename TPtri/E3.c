#include<stdio.h>
#include<string.h>
#define N 50
void affiche(char tab[N][N],int n){
	for(int i=0;i<=n;i++){
		printf("%s ",tab[i]);
		
	}
	printf("\n");
}





void tri_indirec(char tab[N][N],int i){
	int tabindi[N];
	char trans[N];
	for(int n=0;n<N;n++){
		tabindi[n]=0;
	}
	for(int j=0;j<=i;j++){
		for(int x=j;x<=i;x++){
			if(strcmp(tab[j],tab[x])>=0){
				tabindi[j]++;
			}
		}
	}
	for(int y=0;y<=i;y++){
		strcpy(trans,tab[y]);
		strcpy(tab[y],tab[tabindi[y]]);
		strcpy(tab[tabindi[y]],trans);
	}

}




int main(){
	char tab[N][N];
	for(int i=0;i<N;i++){
		scanf("%s",tab[i]);
		tri_indirec(tab,i);
		affiche(tab,i);
	}	

}