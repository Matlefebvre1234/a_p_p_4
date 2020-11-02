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
int image5[MAX_HAUTEUR][MAX_LARGEUR] = {{120, 140}, {29, 140}};



int main()
{
    int lignes1 = 256;
	int colonnes1 = 256;
    int lignes2 =0;
    int colonnes2 =0;
    int maxval = 256;
    //int histogramme[MAX_VALEUR+1];
    char nom[MAX_CHAINE] = "Sherbrooke_Frontenac_nuit.pgm";
   //char nom[MAX_CHAINE] = "tamere.txt";
   char nom2[MAX_CHAINE] = "citronade.pgm";
    struct MetaData metadonnees;
    
    struct MetaData metadonnees2 = {"Mathieu", "En 2009", "En Sciences Humaines le gros noob"};;
    
	int retour;

    printf("-> Debut!\n");

	// exemple d'appel de fonction
     retour = pgm_lire(nom, image1, 
                      &lignes1, &colonnes1, 
                      &maxval, &metadonnees);
                      
     //retour = pgm_creer_histogramme(image1,lignes1,colonnes1,histogramme);
    

                  
	//retour = pgm_copier(image1, lignes1, colonnes1, image4, &lignes2, &colonnes2);
	// exemple detraitement d'un code de retour (erreur ou reussite)
	printf("\n Eclaircir\n\n");
	//retour = pgm_eclaircir_noircir(image1, lignes1, colonnes1, maxval, 0);
	//retour = pgm_creer_negatif(image1, lignes1, colonnes1, maxval);
	retour = pgm_sont_identiques(image3, 2,3,image5,2,2);
	

			
	printf("-> Retour: ");
	
	if (retour == OK)
		printf("-> OK");
		
	else if(retour == DIFFERENTES)printf("-> DIFFERENTES");
	
	else
		printf("-> ERREUR");
	printf("\n");

	// autre exemple d'appel de fonction
	printf("\n ecrire\n\n");
    pgm_ecrire(nom2, image1, 
               lignes1, colonnes1, 
               maxval, metadonnees2);

    printf("-> Fin!\n");

	
	printf("%d",retour);
	printf("%d",lignes1);
	printf("%d",lignes2);
	printf("%d",colonnes1);
	printf("%d",colonnes2);
	printf("Allo");
    return 0;
}
