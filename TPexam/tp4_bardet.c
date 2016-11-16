/* TP 4 serie statistique */
//TANG YUKE

#include<stdio.h>
#include<stdlib.h>
#include "liste.h"

#define TRUE 1
#define FALSE 0

void afficher()
{
	if(!liste_vide()){
		t_doublet liste;
		printf("La série est ");
		en_tete();
		while(!hors_liste()){
			valeur_elt(&liste);
			for(int i=0;i<liste.nb_occ;i++){
				printf("%i ",liste.valeur);
			}
			suivant();
		}
	}
}

void ajout()
{
	
	int valeur_donner;
	t_doublet doublet_liste;
	int valeur_liste;				//la valeur de t_doubelt dans la liste
	int donner_max=TRUE;				//valeur donnée est un nouveau nombre le plus grand
	printf("Saisir le nombre :");
	scanf("%i",&valeur_donner);
	while(valeur_donner>100||valeur_donner<0){
		printf("La valeur est entre 0 et 100 :");
		scanf("%i",&valeur_donner);
	}
	en_tete();
	while(!hors_liste()){
		valeur_elt(&doublet_liste);
		valeur_liste=doublet_liste.valeur;
			if(valeur_liste==valeur_donner){		//Si la valeur déjà existe
				doublet_liste.nb_occ++;
				modif_elt(doublet_liste);
				donner_max=FALSE;
				en_queue();
				
			}
			else if(valeur_liste>valeur_donner){	//Quand cette valeur donnée n'est pas le plus grand dans la liste
				precedent();
				if(hors_liste()){		//Quand la valeur est le plus petit
					en_tete();
					doublet_liste.valeur=valeur_donner;
					doublet_liste.nb_occ=1;
					ajout_gauche(doublet_liste);	
				}
				else{				//Quand cette valeur est dans le milieux de la liste
					valeur_elt(&doublet_liste);
					if(doublet_liste.valeur<valeur_donner){
						doublet_liste.valeur=valeur_donner;
						doublet_liste.nb_occ=1;
						ajout_droit(doublet_liste);
					}
					donner_max=FALSE;
					en_queue();
					
				}
			}
		suivant();
	}
	if(donner_max==TRUE){		//Quand le valeur est le plus grand
		doublet_liste.valeur=valeur_donner;
		doublet_liste.nb_occ=1;
		en_queue();
		ajout_droit(doublet_liste);
	}
	
	
	
	
}

void moyenne()
{	
	int somme=0;
	float moyen;
	int nb_valeur=0;	//nombre de valeur dans la liste
	t_doublet liste;
	en_tete();
	if(!liste_vide()){
		while(!hors_liste()){
			valeur_elt(&liste);
			somme=liste.valeur*liste.nb_occ+somme;
			nb_valeur=nb_valeur+liste.nb_occ;
			suivant();
		}
		moyen=(float)somme/(float)nb_valeur;
		printf("Le moyen est %.2f\n",moyen);
	}
}

void rang_n()
{
	int n,nb_val=0,rang_faux=TRUE;
	t_doublet liste;
	printf("Saisir le nombre : ");
	scanf("%i",&n);
	en_tete();
	while(!hors_liste()&&n!=0){
		valeur_elt(&liste);
		nb_val=nb_val+liste.nb_occ;
		if(nb_val>=n){
			printf("La valeur rang %i est %i\n",n,liste.valeur);
			en_queue();
			rang_faux=FALSE;
		}
		suivant();
	}
	if(rang_faux==TRUE){
		printf("Ce rang n'exist pas\n");
	}
}

void vider()
{
	init_liste();

}

/*	Programme principal */
int main(void)
{	int choix;

/* Initialisation de la liste */
	init_liste();

/* Affichage du menu et saisie du choix */
	do
	{	printf("\nMenu :\n");
		printf(" 1 - Ajouter une valeur\n");
		printf(" 2 - Calculer la moyenne\n");
		printf(" 3 - Valeur de rang n\n");
		printf(" 4 - Vider la liste\n");
		printf(" 5 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: ajout();		afficher(); break;
			case 2: moyenne();	afficher(); break;
			case 3: rang_n();	afficher(); break;
			case 4: vider();		afficher(); break;
			case 5: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 5\n");
		}
	}
	while(choix!=5);
	printf("Au revoir !\n");
	return EXIT_SUCCESS;
}
