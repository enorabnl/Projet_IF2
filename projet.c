//
// Created by enora on 16/05/2022.
//
#include <stdio.h>
#include "projet.h"
#include<string.h>
#include <stdlib.h>
#include<time.h>


// PARAMETRES ET CREATION DES PARTIES






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




int verif_mot_francais () {
    FILE *fp = fopen("dico.txt", "r ");
    char mot[64];
    char test[64];
    char *succes = NULL;
    if (fp != NULL) {
        printf("tapez un mot\n");
        fgets(mot, 64, stdin);
        mot[strlen(mot) - 1] = '\0';
        do {
            succes = fgets(test, 64, fp);
            test[strlen(test) - 1] = '\0';
            if (strcmp(mot, test) == 0) {
                printf("ok");
            }
        } while (succes != NULL);
    }

    fclose(fp);
}