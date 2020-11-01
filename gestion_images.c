/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/


#include "bibliotheque_images.h"

int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];

int pgm_lire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
             int *p_lignes, int *p_colonnes, 
             int *p_maxval, struct MetaData *p_metadonnees)
{
	FILE *fichierOuvert = fopen(nom_fichier,"r");
	
	if(fichierOuvert == NULL) printf("erreur lecture fichier");
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
		
	}
	fclose(fichierOuvert);
    return OK;
}

int pgm_ecrire(char nom_fichier[], int matrice[MAX_HAUTEUR][MAX_LARGEUR], 
               int lignes, int colonnes, 
               int maxval, struct MetaData metadonnees)
{
    return OK;
}

int main()
{
    int lignes1 =0;
    int colonnes1 =0;
    int lignes2 =0;
    int colonnes2 =0;
    int maxval =0;
   // int histogramme[MAX_VALEUR+1];
    char nom[MAX_CHAINE] = "Sherbrooke_Frontenac_nuit.pgm";
   // char nom[MAX_CHAINE] = "tamere.txt";
    struct MetaData metadonnees;

	int retour;

    printf("-> Debut!\n");

	// exemple d'appel de fonction
    retour = pgm_lire(nom, image1, 
                      &lignes1, &colonnes1, 
                      &maxval, &metadonnees);
                  

	// exemple detraitement d'un code de retour (erreur ou reussite)
	printf("-> Retour: ");
	if (retour == OK)
		printf("-> OK");
	else
		printf("-> ERREUR");
	printf("\n");

	// autre exemple d'appel de fonction
    pgm_ecrire(nom, image1, 
               lignes1, colonnes1, 
               maxval, metadonnees);

    printf("-> Fin!\n");

	
	printf("%d",retour);
	printf("%d",lignes1);
	printf("%d",lignes2);
	printf("%d",colonnes1);
	printf("%d",colonnes2);
	printf("Allo");
    return 0;
}
