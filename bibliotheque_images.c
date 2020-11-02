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
				//printf("%3i",matrice[i][j]);
				//printf(" ");
			}
				//printf("\n");
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

int pgm_copier(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2)
{
		if(lignes1 == 0 && colonnes1 == 0) return ERREUR_TAILLE;
		
		else
		{
			*p_lignes2 = lignes1;
			*p_colonnes2 = colonnes1;
		    
			for(int i = 0; i<lignes1 ;i++)
			{
				for(int j = 0; j<colonnes1; j++)
				{
					matrice2[i][j] = matrice1[i][j];
				}
			}
		
		return OK;
		}
}

int pgm_eclaircir_noircir(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, int valeur)
{
	if(lignes == 0 || colonnes == 0)
	{
		return -1;
	}
	
	else
	{
		for(int i = 0; i<lignes ;i++)
		{
			for(int j = 0; j<colonnes; j++)
			{
				matrice[i][j] += valeur;
			
				if(matrice[i][j] > maxval)
				{	
					matrice[i][j] = maxval;
				}
			
				else if(matrice[i][j] < 0)
				{
					matrice[i][j] = 0;
				}	
			}
		}
	}
	
	return 0;	
}

int pgm_creer_histogramme(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int histogramme[MAX_VALEUR+1])
{
	int ValeurTest[MAX_VALEUR+1];
	
	for(int i =0;i< MAX_VALEUR+1;i++)
	{
		histogramme[i] =0;
		ValeurTest[i] = i;
	}
	
	for(int i =0;i<MAX_HAUTEUR;i++)
	{
		for(int j =0;j<MAX_LARGEUR;j++)
		{
			
			for(int k =0;k<MAX_LARGEUR +1;k++)
			{
				if(matrice[i][j] == ValeurTest[k]) histogramme[k]++;
		
			}
	
		
		
		}
	
	}
	
		for(int k =0;k< MAX_VALEUR+1;k++)
	{
		
				printf("%d",ValeurTest[k]);
				printf(" = ");
				printf("%d\n",histogramme[k]);
	}
	
	return 0;
}
