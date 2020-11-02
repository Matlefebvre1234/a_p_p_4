/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include "bibliotheque_images.h"

int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];
int image3[MAX_HAUTEUR][MAX_LARGEUR] = {{120, 140, 178}, {29, 140, 19}};
int image4[MAX_HAUTEUR][MAX_LARGEUR];


int main()
{
    int lignes1 = 0;
	int colonnes1 = 0;
    int lignes2 =0;
    int colonnes2 =0;
    int maxval = 256;
    int histogramme[MAX_VALEUR+1];
    //char nom[MAX_CHAINE] = "Sherbrooke_Frontenac_nuit.pgm";
    char nom[MAX_CHAINE] = "tamere.txt";
    char nom2[MAX_CHAINE] = "citronade.pgm";
    struct MetaData metadonnees;
    
    struct MetaData metadonnees2 = {"Mathieu", "En 2009", "En Sciences Humaines le gros noob"};;
    
	int retour;

    printf("-> Debut!\n");

	// exemple d'appel de fonction
     retour = pgm_lire(nom, image1, 
                      &lignes1, &colonnes1, 
                      &maxval, &metadonnees);
    //retour = pgm_couleur_preponderante(image1,lignes1,colonnes1);

                  
	//retour = pgm_copier(image1, lignes1, colonnes1, image4, &lignes2, &colonnes2);
	// exemple detraitement d'un code de retour (erreur ou reussite)
//	retour = pgm_eclaircir_noircir(image1, lignes1, colonnes1, 255, 20);
	retour = pgm_extraire(image1,9,0,16,16, &lignes1,&lignes2);
	
	printf("\n Éclaircir : %d, %d\n\n", lignes1, colonnes1);
	
	for(int i = 0; i<lignes1 ;i++)
	{
		for(int j = 0; j<colonnes1; j++)
		{
			printf("%d ", image1[i][j]);
		}
		printf("\n");
	}
			
	printf("-> Retour: ");
	if (retour == OK)
		printf("-> OK");
	else
		printf("-> ERREUR");
	printf("\n");

	// autre exemple d'appel de fonction
    pgm_ecrire(nom2, image1, 
               lignes1, colonnes1, 
               maxval, metadonnees2);

    printf("-> Fin!\n");

	
	printf("%d",retour);
	printf("%d",lignes1);
	//printf("%d",lignes2);
	printf("%d",colonnes1);
	//printf("%d",colonnes2);
	printf("Allo");
    return 0;
}
