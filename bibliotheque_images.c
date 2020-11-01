/********
Fichier: bibliotheque_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/
#include <stdio.h>
#include <stdlib.h>
#include "bibliotheque_images.h"

int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
	/*FILE *fichierOuvert = fopen(nom_fichier,"r");
	
	if(fichierOuvert == NULL) printf("erreur lecture fichier");
	else
	{
		
		char texte[256];
		fgets(texte,256,fichierOuvert); //skip une ligne
		fgets(texte,256,fichierOuvert);//skip une ligne
	
		fscanf(fichierOuvert,"%i %i",*p_lignes,*p_colonnes);
		
		printf("%i",*p_lignes);
		printf("%i",*p_colonnes);
		fclose(fichierOuvert);
		
		
		
	}*/
    return OK;
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{
    return OK;
}
