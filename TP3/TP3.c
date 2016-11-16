#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define N 8
void saisir(int* x,char* nom){
	printf("Saisir le nombre de génération : ");
	scanf("%i",x);
	printf("Saisir le nom du fichier : ");
	scanf("%s",nom);
}

void lirefic(char nom[],int mat[N][N]){
	FILE *fic;
	int x;
	int y;
	fic=fopen(nom,"r");
	int lirexy=0;
	int ecrit=0;
	if(fic==NULL){
		printf("Ce fichier n'existe pas");
	 }
	else{
		fscanf(fic,"%i",&x);
		ecrit++;
		while(!feof(fic)){
			if(lirexy==0){
				fscanf(fic,"%i",&y);
				lirexy=1;
				ecrit++;
			}
			else if(lirexy==1){
				fscanf(fic,"%i",&x);
				lirexy=0;
				ecrit++;			
			}
			if(ecrit==2){
				mat[y][x]=1;
				ecrit=0;			
			}	
		}
		fclose(fic);
	}
}


void affiche(int matauto[N][N]){ 
	system("clear");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			
			printf("%i ",matauto[i][j]);			
		}
		printf("\n");
	}
	sleep(1);
}


void generation(int matauto[N][N],int matnbv[N][N]){
/////////////////////////////////////////////////////////////////////////////////////////////////
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
//////////////////////////////////////////////////////////////////////////
			matnbv[i][j]=0;
			if(i+1<N){
				if(matauto[i+1][j]==1){
					matnbv[i][j]++;					
				}	
				if(j-1>=0){
					if(matauto[i+1][j-1]==1){
						matnbv[i][j]++;					
					}		
				}
				if(j+1<N){
					if(matauto[i+1][j+1]==1){
						matnbv[i][j]++;					
					}		
				}			
			}
//////////////////////////////////////////////////////////////////////////
	
			if(i-1>=0){
				if(matauto[i-1][j]==1){
					matnbv[i][j]++;					
				}	
				if(j-1>=0){
					if(matauto[i-1][j-1]==1){
						matnbv[i][j]++;					
					}		
				}
				if(j+1<N){
					if(matauto[i-1][j+1]==1){
						matnbv[i][j]++;					
					}		
				}					
			}

//////////////////////////////////////////////////////////////////////////

			if(j-1>=0){
					if(matauto[i][j-1]==1){
						matnbv[i][j]++;					
					}			
			}

//////////////////////////////////////////////////////////////////////////

			if(j+1<N){
					if(matauto[i][j+1]==1){
						matnbv[i][j]++;					
					}		
			}
//////////////////////////////////////////////////////////////////////////					
		}
		
	}
/////////////////////////////////////////////////////////////////////////////////////////////////	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(matnbv[i][j]==3&&matauto[i][j]==1||matnbv[i][j]==2&&matauto[i][j]==1){
				matauto[i][j]=1;			
			}
			else if(matnbv[i][j]==3&&matauto[i][j]==0){
				matauto[i][j]=1;	
			}
			else{
				matauto[i][j]==0;			
			}
		}
	}


}






void main(){
	int x;
	char nom[50];
	int matauto[N][N];
	int matnbv[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			matauto[i][j]=0;
			matnbv[i][j]=0;	
		}
	}
	saisir(&x,nom);
	lirefic(nom,matauto);
	for(int i=0;i<=x;i++){
		generation(matauto,matnbv);
		affiche(matauto);
		affiche(matnbv);
		
			
	}
}











