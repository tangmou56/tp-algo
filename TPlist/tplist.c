#include<stdio.h>
#include<stdlib.h>
#include "list.h"

/* Fonctions de manipulation de la liste */

void afficher(void)
/* Affiche les valeurs de la liste */
{
	int elem;

	if(liste_vide())
		printf("La liste est vide\n");
	else
	{
		printf("\nLa liste contient: ");
		en_tete();
		while(!hors_liste())
		{
			valeur_elt(&elem);
			printf("%i ",elem);
			suivant();
		}
		printf("\n");
	}
}

void inserer(void)
/* Insere un �l�ment dans la liste */
{
	int valeur,elem;
	printf("Saisir un élément: ");
	scanf("%i",&valeur);
	en_queue();
	if(liste_vide()){
		ajout_droit(valeur);
	}
	else{
		valeur_elt(&elem);
		while(!hors_liste()&&valeur<=elem){
			precedent();
			valeur_elt(&elem);
		}
		ajout_droit(valeur);
	}
	
}

void supprimer(void)
/* Supprime toutes les occurrences d'un entier lu au clavier */
{
	int valeur,elem;
	printf("Saisir un élément: ");
	scanf("%i",&valeur);
	en_queue();
	if(liste_vide()){
		printf("La liste est vide. \n");
	}
	else{
		while(!hors_liste()){
			valeur_elt(&elem);
			if(valeur==elem){
				oter_elt();
			}
			else{
				precedent();
			}
		}
	}

}

void afficher_multiples(void)
/* Affiche tous les multiples d'une valeur lue au clavier */
{
	int valeur,elem;
	printf("Saisir un élément: ");
	scanf("%i",&valeur);
	en_tete();
	if(liste_vide()){
		printf("La liste est vide. \n");
	}
	else{
		printf("Les multiples sont: ");
		while(!hors_liste()){
			valeur_elt(&elem);
			if(elem%valeur==0){
				printf("%i ",elem);
			}
			
				suivant();
			
		}
	}
}

void vider_liste(void)
/* Supprime tous les �l�ments de la liste */
{
	init_liste();

}

/*	Programme principal */
int main(void)
{	int choix;

/* Initialisation de la liste d'entiers */
	init_liste();

	do
/* Affichage du menu et saisie du choix */
	{	printf("\nMenu :\n");
		printf(" 1 - Inserer une valeur\n");
		printf(" 2 - Supprimer une valeur\n");
		printf(" 3 - Afficher les multiples\n");
		printf(" 4 - Vider la liste\n");
		printf(" 5 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: inserer();  afficher(); break;
			case 2: supprimer(); afficher(); break;
			case 3: afficher_multiples(); afficher(); break;
			case 4: vider_liste(); afficher(); break;
			case 5: break;
			default: printf("Erreur: votre choix doit �tre compris entre 1 et 5\n");
		}
	}
	while(choix!=5);

	printf("Au revoir !\n");
	return EXIT_SUCCESS;
}
