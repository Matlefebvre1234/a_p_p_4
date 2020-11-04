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

		fscanf(fichierOuvert,"%i %i",p_colonnes,p_lignes);
		printf("%i\n",*p_colonnes);
		printf("%i ",*p_lignes);
		
		
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
			//	printf("\n");
		}

		return OK;
	}
	fclose(fichierOuvert);

}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{
	FILE *fichierOuvert = fopen(nom_fichier, "w");
	
	if(fichierOuvert == NULL) return ERREUR_FICHIER;
	
	else
	{
	fprintf(fichierOuvert, "P2\n");
	fprintf(fichierOuvert, "# %s; %s; %s\n", metadonnees.auteur, metadonnees.dateCreation, metadonnees.lieuCreation);
	fprintf(fichierOuvert, "%d %d\n", colonnes, lignes);
	fprintf(fichierOuvert, "%d\n", maxval);
	
	for(int i = 0; i<lignes ;i++)
		{
			for(int j = 0; j<colonnes; j++)
			{
				fprintf(fichierOuvert, "%d ", matrice[i][j]);
				printf("%d ", matrice[i][j]);
			}
			
			fprintf(fichierOuvert, "\n");
			printf("\n");
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
				matrice[i][j] = matrice[i][j] + valeur;
				printf("%d ", matrice[i][j]);
				
				if(matrice[i][j] > maxval)
				{	
					matrice[i][j] = maxval;
				}
			
				else if(matrice[i][j] < 0)
				{
					matrice[i][j] = 0;
				}
					
			}
			
			printf("\n");
		}
	}
	
	return 0;	
}

int pgm_creer_histogramme(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int histogramme[MAX_VALEUR+1])
{
	int ValeurTest[MAX_VALEUR+1];
	
	for(int i =0;i< MAX_VALEUR+1;i++)
	{
		histogramme[i] =-1;
		ValeurTest[i] = i;
	}
	
	for(int i =0;i<lignes;i++)
	{
		for(int j =0;j<colonnes;j++)
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



int pgm_couleur_preponderante(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes)
{
	 int histogramme[MAX_VALEUR+1];
	 int valeurHistogrammeMax = 0;
	 int positionValeurMax=0;
	 
	 pgm_creer_histogramme(matrice,lignes,colonnes,histogramme);
	
	for(int i =0;i<MAX_VALEUR+1;i++)
	{
		
		if(histogramme[i] > valeurHistogrammeMax)
		{
			valeurHistogrammeMax = histogramme[i];
			positionValeurMax = i;
			
		}
		
	}
	printf("\ncouleur pre ponderante = ");
	printf("%d",positionValeurMax);
	return positionValeurMax;
}

int pgm_extraire(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int lignes2, int colonnes2, int *p_lignes, int *p_colonnes)
{
	int matriceExtrait[MAX_HAUTEUR][MAX_LARGEUR];
	int k =0;//compteur pour incrémentation
	int z =0;//compteur pour incrémentation
	
	
	for(int i =lignes1; i <= lignes2;i++)
	{
		
		z =0;	
		for(int j =colonnes1; j <= colonnes2;j++)
		{
			
			if(i >= MAX_HAUTEUR || j >= MAX_LARGEUR)return -1;
			matriceExtrait[k][z] = matrice[i][j];
			z++;
			
		} 
		k++;
	
	} 
	
	int ligne= lignes2 -lignes1;
	int colonne = colonnes2 -colonnes1;
	*p_lignes = ligne;
	*p_colonnes = colonne;
	printf("%d",*p_lignes);
	printf("%d",*p_colonnes);
	k=0;
	z=0;
	for(int i =0; i <= ligne;i++)
	{
		z =0;	
		for(int j =0; j <= colonne;j++)
		{
			matrice[k][z] = matriceExtrait[k][z];
			z++;	
		
		} 
		k++;
	} 
	
	return 0;
}

int pgm_creer_negatif(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval)
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
				matrice[i][j]  = maxval - matrice[i][j];
			}
		}
		
		return 0;
	}
}

int pgm_sont_identiques(int matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, int matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2)
{
	if(colonnes1 == 0 || lignes1 == 0 || colonnes2 == 0 || lignes2 == 0) return -1;
	
	else
	{
		if(colonnes1 != colonnes2 || lignes1 != lignes2) return 1;
		
		else
		{
			for(int i = 0; i<lignes1 ;i++)
			{
				for(int j = 0; j<colonnes1; j++)
				{
					if(matrice1[i][j] != matrice2[i][j]) return 1;
				}
			}
		}
		
		
		return 0;
	}
}

int pgm_pivoter90(int matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int sens)
{
    int temp[MAX_HAUTEUR][MAX_LARGEUR];
    int temp1 = *p_colonnes;
	int lignes;
	int colonnes;

    printf("%d %d", *p_lignes, *p_colonnes);

    pgm_copier(matrice, *p_lignes, *p_colonnes, temp, &lignes, &colonnes);

    *p_colonnes = *p_lignes;
    *p_lignes = temp1;
     lignes = *p_colonnes;
     colonnes = *p_lignes;

    for(int i = 0; i<*p_lignes ;i++)
        {
            for(int j = 0; j<*p_colonnes; j++)
            {
                matrice[i][j] = temp[j][i];
                //printf("%d", matrice[i][j]);
            }
            //printf("\n");
        }

    printf("\n");

    for(int i = 0; i<lignes ;i++)
        {
		
            for(int j = 0; j<colonnes; j++)
            {
                matrice[i][j] = temp[lignes - j - 1][i];
               
                //printf("%d", matrice[i][j]);
            }
            //printf("\n");
     
        }

    return 0;
}

int ppm_lire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes, int *p_colonnes, int *p_maxval, struct MetaData *p_metadonnees)
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
				fscanf(fichierOuvert,"%i %i %i",&matrice[i][j].valeurR, &matrice[i][j].valeurG, &matrice[i][j].valeurB);
				printf("%i %i %i ",matrice[i][j].valeurR, matrice[i][j].valeurG, matrice[i][j].valeurB);
			}
				printf("\n");
		}

		return OK;
	}
	fclose(fichierOuvert);

}

int ppm_ecrire(char nom_fichier[], struct RGB matrice[MAX_HAUTEUR][MAX_LARGEUR], int lignes, int colonnes, int maxval, struct MetaData metadonnees)
{
	FILE *fichierOuvert = fopen(nom_fichier, "w");
	
	if(fichierOuvert == NULL) return ERREUR_FICHIER;
	
	else
	{
	fprintf(fichierOuvert, "P3\n");
	fprintf(fichierOuvert, "# %s; %s; %s\n", metadonnees.auteur, metadonnees.dateCreation, metadonnees.lieuCreation);
	fprintf(fichierOuvert, "%d %d\n", lignes, colonnes);
	fprintf(fichierOuvert, "%d\n", maxval);
	
	for(int i = 0; i<lignes ;i++)
		{
			for(int j = 0; j<colonnes; j++)
			{
				fprintf(fichierOuvert, "%d %d %d ", matrice[i][j].valeurR, matrice[i][j].valeurG, matrice[i][j].valeurB);
			}
			
			fprintf(fichierOuvert, "\n");
		}
		
	fclose(fichierOuvert);
    return OK;
	}
}

int ppm_copier(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int *p_lignes2, int *p_colonnes2)
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
					matrice2[i][j].valeurR = matrice1[i][j].valeurR;
					matrice2[i][j].valeurG = matrice1[i][j].valeurG;
					matrice2[i][j].valeurB = matrice1[i][j].valeurB;
				}
			}
		
		return OK;
		}
}

int ppm_sont_identiques(struct RGB matrice1[MAX_HAUTEUR][MAX_LARGEUR], int lignes1, int colonnes1, struct RGB matrice2[MAX_HAUTEUR][MAX_LARGEUR], int lignes2, int colonnes2)
{
	if(colonnes1 == 0 || lignes1 == 0 || colonnes2 == 0 || lignes2 == 0) return -1;
	
	else
	{
		if(colonnes1 != colonnes2 || lignes1 != lignes2) return 1;
		
		else
		{
			for(int i = 0; i<lignes1 ;i++)
			{
				for(int j = 0; j<colonnes1; j++)
				{
					if( matrice1[i][j].valeurR != matrice2[i][j].valeurR || matrice1[i][j].valeurG != matrice2[i][j].valeurG || matrice1[i][j].valeurB != matrice2[i][j].valeurB) return 1;
				}
			}
		}
		
		
		return 0;
	}
}






























































