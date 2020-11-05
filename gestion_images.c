/********
Fichier: gestion_images.c
Auteurs: Domingo Palao Munoz
         Charles-Antoine Brunet
Date: 25 octobre 2018
Description: Fichier de distribution pour GEN145.
********/

#include <stdio.h>
#include "bibliotheque_images.h"
#include "AutoValidation.h"

int image1[MAX_HAUTEUR][MAX_LARGEUR];
int image2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB1[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB2[MAX_HAUTEUR][MAX_LARGEUR];
struct RGB imageRGB3[MAX_HAUTEUR][MAX_HAUTEUR];
int image3[MAX_HAUTEUR][MAX_LARGEUR] = {{120, 140, 178}, {29, 140, 19}};
int image4[MAX_HAUTEUR][MAX_LARGEUR];
int image5[MAX_HAUTEUR][MAX_LARGEUR] = {{120, 140}, {29, 140}};



int main()
{
	AutoValidation();
	
	

	//test_pgm_ecrire(); //erreur
	//test_pgm_extraire(); //erreur
	//test_pgm_lire();//erreur
	//test_pgm_pivoter90(); //erreur
	//test_ppm_lire(); //erreur
	//test_ppm_pivoter90();//erreur
	
	
    /*int lignes1 = 0;
	int colonnes1 = 0;
    int lignes2 =0;
    int maxval = 256;
    //int histogramme[MAX_VALEUR+1];
   //char nom[MAX_CHAINE] = "Sherbrooke_Frontenac_nuit.pgm";
   //char nom[MAX_CHAINE] = "Sherbrooke_Frontenac_nuit.ppm";
  // char nom[MAX_CHAINE] = "tamere.pgm";
   //char nom2[MAX_CHAINE] = "citronade.pgm";
  //char nom2[MAX_CHAINE] = "citronade.ppm";
    struct MetaData metadonnees;
    
    struct MetaData metadonnees2 = {"Mathieu", "En 2009", "En Sciences Humaines le gros noob"};;
    
	int retour;

    printf("-> Debut!\n");
	printf("\n Lire\n\n");
	// exemple d'appel de fonction
     retour = pgm_lire(nom, image1, 
                      &lignes1, &colonnes1, 
                      &maxval, &metadonnees);
                      
     //retour = ppm_lire(nom, imageRGB1, 
                      //&lignes1, &colonnes1, 
                      //&maxval, &metadonnees);
	
	 printf("-> Retour: ");
	 if (retour == OK)
		printf("-> OK");
		
	 else if(retour == DIFFERENTES)printf("-> DIFFERENTES");
	 else if(retour == ERREUR_FICHIER)printf("-> ERREUR_FICHIER");
	 else if(retour == ERREUR_FORMAT)printf("-> ERREUR_FORMAT");
	 else if(retour == ERREUR_TAILLE)printf("-> ERREUR_TAILLE");
	
	 else
	printf("-> ERREUR");
	printf("\n");
	
     //retour = pgm_creer_histogramme(image1,lignes1,colonnes1,histogramme);
    

                  
	//retour = pgm_copier(image1, lignes1, colonnes1, image4, &lignes2, &colonnes2);
	// exemple detraitement d'un code de retour (erreur ou reussite)
	printf("\n Copier\n\n");
	//retour = pgm_eclaircir_noircir(image1, lignes1, colonnes1, maxval, 0);
	//retour = pgm_creer_negatif(image1, lignes1, colonnes1, maxval);
	//retour = pgm_sont_identiques(image3, 2,3,image5,2,2);
	//retour = pgm_pivoter90(image1, &lignes1, &colonnes1, 0);
	//retour = pgm_extraire(image1,150,50,190,100, &lignes1,&colonnes1);
	//retour = pgm_pivoter90(image1, &lignes1, &colonnes1, 1);
	//retour = pgm_extraire(image1,1,1,3,3, &lignes1,&colonnes1);
	//retour = pgm_eclaircir_noircir(image1, lignes1, colonnes1, 255, 20);
	//retour = ppm_copier(imageRGB1, lignes1, colonnes1, imageRGB2, &lignes2, &colonnes2);
	//retour = ppm_sont_identiques(imageRGB1, lignes1, colonnes1, imageRGB3, lignes2, colonnes2);
	//retour = ppm_pivoter90(imageRGB1, &lignes1, &colonnes1, 1);

	printf("-> Retour: ");
	 if (retour == OK)
		printf("-> OK");
		
	 else if(retour == DIFFERENTES)printf("-> DIFFERENTES");
	 else if(retour == ERREUR_FICHIER)printf("-> ERREUR_FICHIER");
	 else if(retour == ERREUR_FORMAT)printf("-> ERREUR_FORMAT");
	 else if(retour == ERREUR_TAILLE)printf("-> ERREUR_TAILLE");
	
	 else
	printf("-> ERREUR");
	printf("\n");

	// autre exemple d'appel de fonction
	printf("\n Ecrire\n\n");
    retour = ppm_ecrire(nom2, imageRGB1, 
               lignes1, colonnes1, 
               maxval, metadonnees2);
               
    retour = pgm_ecrire(nom2, image1, 
               lignes1, colonnes1, 
               maxval, metadonnees2);
               
	
	printf("-> Retour: ");
	if (retour == OK)
		printf("-> OK");
		
	else if(retour == DIFFERENTES)printf("-> DIFFERENTES");
	
	else
		printf("-> ERREUR");
	printf("\n");
	
    printf("-> Fin!\n");

	//printf("%d",retour);
	//printf("%d",lignes1);
	////printf("%d",lignes2);
	//printf("%d",colonnes1);
	////printf("%d",colonnes2);
	//printf("Allo");*/


    return 0;
}
