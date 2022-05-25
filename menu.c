//
// Created by enora on 23/05/2022.
//
//
// Created by enora on 16/05/2022.
//

#include "menu.h"


#include<string.h>
#include <stdlib.h>
#include<time.h>
#include <stdio.h>

int menu_principal(){
    int choix = 0;
    printf("**\n");
    printf("**\nBienvenue sur le jeu du Boggle !\n**\n");
    printf("**\n");
    printf("Menu principal :\n");                  //juste pour faire "beau"

    do{
        printf("Tapez 1 pour demarrer une partie.\nTapez 2 pour afficher les meilleurs scores.\nTapez 3 pour quitter le jeu.\n");
        scanf("%d", &choix);
    }while(choix<1 || choix>3); //redemande tant que le chiffre donné n'est pas correct

    return choix;
}

int menu_scores() {
    int choix_score = 0;

    printf("Vous avez choisi d'afficher les meilleurs scores.\n");
    do {
        printf("Tapez 1 pour recherhcer un utilisateur et afficher son meilleur score.\nTapez 2 pour afficher les resulats selon la taille de la grille.\nTapez 3 pour revenir au menu principal.\n");
        scanf("%d", &choix_score);
    } while (choix_score < 1 || choix_score > 3);

    return choix_score;
}
