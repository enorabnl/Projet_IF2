#include "projet.h"
#include "menu.h"
#include "creation_parties.h."

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int choix_menu_principal, choix_menu_scores;
    int dimension_grille;
    int duree;
    choix_menu_principal = menu_principal();

    switch (choix_menu_principal) {
        case 1 :
            //printf("Vous avez choisi de demarrer une partie.\n");

            break;
        case 2 :
            choix_menu_scores = menu_scores();
            if(choix_menu_scores==1){
                printf("useur.\n"); //juste pour tester faudra enlever
                // chercher par utlisateur
                //un fichier par ulisateur je pense + un ficher par taille de grille
            }else if(choix_menu_scores==2){
                printf("taille.\n");
                //afficher selon taille de grille
            }else{
                printf("retour menu.\n");
                choix_menu_principal = menu_principal();
            }
            break;

        case 3 :
            exit(1);
            break;
        default:
            printf("***Erreur***\n");
    }
    lettre_random();


    return 0;
}


