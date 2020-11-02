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
	FILE *fichierOuvert = fopen(nom_fichier,"r");
	
	if(fichierOuvert == NULL) return ERREUR_FICHIER;
	
	else if(*p_lignes > MAX_HAUTEUR && *p_colonnes > MAX_HAUTEUR) return ERREUR_TAILLE;
	
	else if (*p_maxval>MAX_VALEUR) return ERREUR_FORMAT;
	
	else
	{		
		char texte[256];

		fgets(texte,256,fichierOuvert); //skip une lignep
		printf("%s",texte);

		fscanf(fichierOuvert,"%i %i",p_lignes,p_colonnes);
		printf("%i ",*p_lignes);
		printf("%i\n",*p_colonnes);
		
		fscanf(fichierOuvert,"%i\n",p_maxval);
		printf("%i\n",*p_maxval);
		
		for(int i =0;i<*p_lignes;i++)
		{
			
			for(int j =0;j<*p_colonnes;j++)
			{
				fscanf(fichierOuvert,"%i",&matrice[i][j]);
				printf("%3i",matrice[i][j]);
				printf(" ");
			}
				printf("\n");
		}

		return OK;
	}
	fclose(fichierOuvert);

}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{
	FILE *fichierOuvert = fopen(nom_fichier, "a");
	
	if(fichierOuvert == NULL) return ERREUR_FICHIER;
	
	else
	{
	fprintf(fichierOuvert, "%s; %s; %s\n", metadonnees.auteur, metadonnees.dateCreation, metadonnees.lieuCreation);
	fprintf(fichierOuvert, "%d %d\n", lignes, colonnes);
	fprintf(fichierOuvert, "%d\n", maxval);
	
	for(int i = 0; i<lignes ;i++)
		{
			for(int j = 0; j<colonnes; j++)
			{
				fprintf(fichierOuvert, "%d ", matrice[i][j]);
			}
			
			fprintf(fichierOuvert, "\n");
		}
	
	fclose(fichierOuvert);
    return OK;
	}
}
