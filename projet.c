//
// Created by enora on 16/05/2022.
//
#include <stdio.h>
#include "projet.h"
#include<string.h>
#include <stdlib.h>
#include<time.h>

// MENUS


int menu_principal(){
    int choix = 0;
    printf("**\n");
    printf("Bienvenue sur le jeu du Boggle !\n");
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

// PARAMETRES ET CREATION DES PARTIES

void duree_partie(int duree){
    do{
        printf("Combien de temps voulez-vous jouer (60s mini 180s maxi)");
        scanf("%d",&duree);
    }while(duree<60 || duree>180);
}


char lettre_random() {
    char lettre = 'a';
    int nb;
    srand(time(0));

    nb = rand() % 100001;
    printf("%d", nb);

    switch(nb){
        case 0 ... 8182 :    lettre = 'A'; break;
        case 8183 ... 9084 : lettre = 'B';break;
        case 9085 ... 12433 : lettre ='C';break;
        case 12434 ... 16106 : lettre = 'D';break;
        case 
        default:
            printf("erreur");
    }
    printf("%c",lettre);


    return lettre;
}






// DEROULEMENT DE LA PARTIE

/* Cette fonction compare la première lettre du mot entré (ex : E) avec toutes les lettres de la grille
 * et stock ses positions (stock la position de tous les E de la grille
*/
void recherche_premiere_lettre (int compteur,int dim_grille,char grille[][dim_grille],char mot[],structure_lettre position_prem_lettre[]){
    compteur=0;
    for(int ligne_grille=0;ligne_grille<dim_grille;ligne_grille++){
        for(int colone_grille=0;colone_grille<dim_grille;colone_grille++){
            if(grille[ligne_grille][colone_grille]==mot[0]){
                position_prem_lettre[compteur].lettre= grille[ligne_grille][colone_grille];
                position_prem_lettre[compteur].position.x=ligne_grille;
                position_prem_lettre[compteur].position.y=colone_grille;
                compteur += 1;
            }
        }
    }
}
// le compteur est le nombre de fois que la premiere lettre apparait ds la grille
int verif_lien_entre_lettres(int compteur,int dim_grille,char grille[][dim_grille],char mot[],structure_lettre position_prem_lettre[]) {
    int num_lettre_mot = 1, num_prem_lettre = 0, ok;
    structure_lettre lettre_reference, lettre_suivante;

    lettre_reference = position_prem_lettre[num_prem_lettre];
    do {
        for (int x = lettre_reference.position.x - 1; x < lettre_reference.position.x + 2; x++) {
            printf("ligne : %d\n", x);
            for (int y = lettre_reference.position.y - 1; y < lettre_reference.position.y + 2; y++) {
                printf("colone : %d\n", y);
                printf("%c\n", grille[x][y]);
                if (grille[x][y] == mot[num_lettre_mot] &&
                    (x != lettre_reference.position.x || y != lettre_reference.position.y)) {
                    lettre_suivante.lettre = grille[x][y];
                    printf("%c\n", lettre_suivante.lettre);
                    lettre_suivante.position.x = x;
                    lettre_suivante.position.y = y;
                    printf("trouve\n");
                    ok = 0;
                } else {
                    ok = 1;
                }
            }
        }
        if (ok == 0) {
            lettre_reference.lettre = lettre_suivante.lettre;
            lettre_reference.position.x = lettre_suivante.position.x;
            lettre_reference.position.y = lettre_suivante.position.y;
            num_lettre_mot += 1;
        }
    } while (ok == 0 && num_lettre_mot < strlen(mot));
    return ok;
}



