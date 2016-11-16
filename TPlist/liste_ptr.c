/* Mise en oeuvre contigue d'une liste d'entiers */
#define TAILLE_MAX 100
#include<stdio.h>
#include<stdlib.h>

typedef struct element{int nombres;struct element *suiv;struct element *pred;}t_element;

/* D�claration des indices de queue et d'�l�ment courant */

t_element *drapeau;
t_element *ec;
void init_liste(void)
/* Initialise la liste � vide */
{	
	drapeau=malloc(sizeof(t_element));
	drapeau->suiv=drapeau;
	drapeau->pred=drapeau;
}

int liste_vide(void)
/* Rend vrai si la liste est vide, faux sinon */
{	
	return (drapeau->suiv==drapeau);
}

int hors_liste(void)
/* Rend vrai si l'elt courant est hors de la liste, faux sinon */
{	
	return(*ec==drapeau);
}

void en_tete(void)
/* Positionne en tete de la liste */
{	
	if(!liste_vide()) 
		ec=drapeau->suiv;
}

void en_queue(void)
/* Positionne en queue de la liste */
{	
	if(!liste_vide()) 
		ec = drapeau->pred;
}

void precedent(void)
/* Positionne sur l'elt precedent*/
{	
	if(!hors_liste()) 
		ec=ec->pred;
}

void suivant(void)
/* Positionne sur l'elt suivant*/
{	
	if(!hors_liste()) 
		ec=ec->suiv;
}

void valeur_elt(int* v)
/* Renvoie dans e la veleur de l'elt courant */
{	
	if(!hors_liste()) 
		*v= ec->nombre;
}

void modif_elt(int v)
/* Affecte v � l'elt courant */
{	
	if(!hors_liste()) 
		ec->nombre=v;
}

void oter_elt(void)
/* Supprime l'elt courant et positionne sur le precedent */
{	
	int i;
	if(!hors_liste())
	{	
		(ec->pred)->suiv=ec->suiv;
		(ec->suiv)->pred=ec->pred;
		precedent();
	}
}

void ajout_droit(int v)
/* Ajoute v a droite de l'elt courant */
{	
	int i;
	
	if(liste_vide()||!hors_liste())
	{	
		t_element nouv;
		nouv.nombre=v;
		nouv.pred=ec;
		nouv.suiv=ec->suiv;
		ec->suiv=&nouv;
		(ec->suiv)->pred=&nouv;
	}
}

void ajout_gauche(int v)
/* Ajoute v a gauche de l'elt courant */
{	
	int i;
	
	if(liste_vide())
		ec++;

	if(liste_vide()||!hors_liste())
	{	
		for(i=queue;i>=ec;i--)
			liste[i+1]=liste[i];
		liste[ec]=v;
		queue++;
	}
}