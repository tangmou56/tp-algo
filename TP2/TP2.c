/* Menu du TP 2 - Base de donnees sur des personnes*/
#include<stdio.h>
#include<string.h>
#define N 50

/* Definition du type date (jour, mois, annee) */
typedef struct { int jour, mois, an; } t_date;

/* Definition du type sexe avec la convention INSEE */
typedef enum { homme = 1, femme } t_sexe;

/* Definition du type personne (prenom, sexe, date de naissance) */
typedef struct { char prenom[20] ; t_sexe sexe ; t_date naissance ; } t_personne ;

	
void afficher_base(t_personne* amis, int nb_amis)
{
	
	char sex[20];
	for(int i=0;i<nb_amis;i++){
		if(amis[i].sexe==1){
			strcpy(sex, "homme");		
		}
		else{
			strcpy(sex, "femme");		
		}

		printf("%s %s %i,%i,%i\n",amis[i].prenom,sex,amis[i].naissance.jour,amis[i].naissance.mois,amis[i].naissance.an);
		
		}

}

void afficher_nombre_fh(t_personne* amis, int nb_amis)
{	
	int homme=0;
	int femme=0;
	for(int i=0;i<nb_amis;i++){
		if(amis[i].sexe==1){
			homme++;		
		}
		else{
			femme++;	
		}
	}
	printf("%i hommes,%i femmes",homme,femme);
}

void afficher_cadet(t_personne* amis, int nb_amis)
{
	int n_jeu;
	long datemax=0;
	for(int i=0;i<nb_amis;i++){
		if(amis[i].naissance.an*1000+amis[i].naissance.mois*50+amis[i].naissance.jour>datemax){
				datemax=amis[i].naissance.an*1000+amis[i].naissance.mois*50+amis[i].naissance.jour;
				n_jeu=i;
		}
	}
	printf("Le plus jeune est %s",amis[n_jeu].prenom);


}

void afficher_anniv(t_personne* amis, int nb_amis)
{	
	char pren[20];
	printf("Saisir le prenom: ");
	scanf("%s",pren);
	/*nombre de trouvé*/
	int a_trouve=0;
	/*nombre de trouvé*/
	for(int i=0;i<nb_amis;i++){
		if(strcmp(pren,amis[i].prenom)==0){
			a_trouve++;
			printf("Le date de naissance est %i,%i,%i\n",amis[i].naissance.jour,amis[i].naissance.mois,amis[i].naissance.an);	
		}
	}
	if(a_trouve==0){
		printf("Ne trouve pas ce personne");	
	}
}	

void ajouter_personne(t_personne* amis, int* nb_amis)
{	
	int t_jour[12];
	/*Tableau pour verifier le jour*/
	t_jour[1]=31;t_jour[2]=28;t_jour[3]=31;t_jour[4]=30;t_jour[5]=31;t_jour[6]=30;t_jour[7]=31;t_jour[8]=31;t_jour[9]=30;t_jour[10]=31;t_jour[11]=30;t_jour[12]=31;
	/*Tableau pour verifier le jour*/

	/*valeur saisie*/
	char prenom[20];
	int sex;
	int jour,moi,an;
	/*valeur saisie*/

	/*Saisir de l'information*/
	printf("Saisir le prenom: ");
	scanf("%s",prenom);
	printf("Saisir le sexe,1 vaut homme,2 vaut femme: ");
	scanf("%i",&sex);
	while(sex!=1 && sex!=2){
		printf("Saisir le sexe,1 vaut homme,2 vaut femme: ");
		scanf("%i",&sex);
	}
	printf("Saisir le jour de naissance: ");
	scanf("%i",&jour);
	while(jour<=0 || jour>31){
		printf("Saisir le jour de naissance: ");
		scanf("%i",&jour);
	}
	printf("Saisir le mois de naissance: ");
	scanf("%i",&moi);
	while(moi<=0 || moi>12){
		printf("Saisir le mois de naissance: ");
		scanf("%i",&moi);	
	}
	while(jour>t_jour[moi]||jour<=0){
		printf("Le jour siasie est incorrecte,siasir le jour correcte: ");
		scanf("%i",&jour);
	}

	printf("Saisir l'année de naissance: ");
	scanf("%i",&an);
	while(an<=0){
		printf("Saisir l'année de naissance: ");
		scanf("%i",&an);	
	}
	/*Saisir de l'information*/

	/*ajourter à la liste*/
	strcpy(amis[*nb_amis].prenom,prenom);
	amis[*nb_amis].sexe=sex;
	amis[*nb_amis].naissance.jour=jour;
	amis[*nb_amis].naissance.mois=moi;
	amis[*nb_amis].naissance.an=an;	
	/*ajourter à la liste*/
	*nb_amis=*nb_amis+1;
	

}

/* Programme principal */
int main()
{	

	/* Declaration de la base de donnees, de taille maximale 50 et de taille utile nb_amis */
	t_personne amis[N]={{"Elodie",femme,{30,5,1996}}, {"Julien",homme,{8,11,1996}},{"Camille",femme,{2,6,1995}}, {"Adrien",homme,{20,11,1996}},{"Camille",homme,{12,5,1994}}, {"Lise",femme,{5,10,1995}}} ;
	int nb_amis = 6 ;

	int choix;	/* Choix de l'utilisateur */

	do
	{	/* Affichage du menu */
		printf("\nMenu :\n");
		printf(" 1 - Afficher le contenu de la base\n");
		printf(" 2 - Afficher le nombre d'hommes et de femmes\n");
		printf(" 3 - Afficher le prenom de la personne la plus jeune\n");
		printf(" 4 - Afficher les anniversaires d'un prenom\n");
		printf(" 5 - Ajouter une personne\n");
		printf(" 6 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1 : afficher_base(amis,nb_amis); break;
			case 2:  afficher_nombre_fh(amis,nb_amis); break;
			case 3:  afficher_cadet(amis,nb_amis); break;
			case 4:  afficher_anniv(amis,nb_amis); break;
			case 5:  ajouter_personne(amis,&nb_amis); break;
			case 6:  break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
		}
	}
	while(choix!=6);
	printf("Au revoir !\n");
	return 0;
}
