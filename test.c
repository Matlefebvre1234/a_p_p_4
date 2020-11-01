/*
 * test.c
 * 
 * Copyright 2020 Utilisateur <Utilisateur@PC-DE-MAT>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include "bibliotheque_images.h"
int main(int argc, char **argv)
{
	int lignes1 =0;
    int colonnes1 =0;
    int lignes2 =0;
    int colonnes2 =0;
    
     int maxval =0;
    char nom[MAX_CHAINE] = "Sherbrooke_Frontenac_nuit.pgm";
    struct MetaData metadonnees;
    pgm_lire(nom, image1,&lignes1, &colonnes1, &maxval, &metadonnees);
	/*FILE *fichierOuvert = fopen("Sherbrooke_Frontenac_nuit.pgm","r");
	
	if(fichierOuvert == NULL) printf("erreur lecture fichier");
	else
	{
		
		char texte[256];
		char ligne[256];
		char colonne[256];
		//fgets(texte,256,fichierOuvert); //skip une ligne
		//fgets(texte,256,fichierOuvert);//skip une ligne
	
		
		fgets(texte,255,fichierOuvert);
		printf("%s",texte);
		
		fscanf(fichierOuvert,"%s %s",ligne,colonne);
		printf("%s",ligne);
		printf("%s",colonne);
		fclose(fichierOuvert);
	}
	printf("ta mere");*/
	return 0;
}

