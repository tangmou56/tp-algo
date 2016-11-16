#include"pile.h"


int sommet=0;
int pile[N];

void empiler(int n){
	pile[sommet]=n;
	sommet++;
}

void depiler(int* n){
	sommet--;
	*n=pile[sommet];
	

}