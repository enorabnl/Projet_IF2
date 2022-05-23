//
// Created by enora on 16/05/2022.
//
#include <stdio.h>
#include "projet.h"
#include<string.h>
#include <stdlib.h>
#include<time.h>


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
        case 16107 ... 32832 : lettre = 'E';break;
        case 32833 ... 33899 : lettre = 'F';break;
        case 33900 ... 34766 : lettre = 'G';break;
        case 34767 ... 35504 : lettre = 'H';break;
        case 35505 ... 43091 : lettre = 'I';break;
        case 43092 ... 43705 : lettre = 'J';break;
        case 43706 ... 43779 : lettre = 'K';break;
        case 43780 ... 48241 : lettre = 'L';break;
        case 48242 ... 52212 : lettre = 'M';break;
        case 52213 ... 59315 : lettre = 'N';break;
        case 59316 ... 65117 : lettre = 'O';break;
        case 65118 ... 67641 : lettre = 'P';break;
        case 67642 ... 69004 : lettre = 'Q';break;
        case 69005 ... 75704 : lettre = 'R';break;
        case 75705 ... 83661 : lettre = 'S';break;
        case 83662 ... 90913 : lettre = 'T';break;
        case 90914 ... 97231 : lettre = 'U';break;
        case 97232 ... 99071 : lettre = 'V';break;
        case 99072 ... 99120 : lettre = 'W';break;
        case 99121 ... 99547 : lettre = 'X';break;
        case 99548 ... 99675 : lettre = 'Y';break;
        case 99676 ... 100001 : lettre = 'Z';break;
        default:
            printf("erreur");
    }
    printf("%c",lettre);
    return lettre;
}

int unicite_lettre_3_3 (int dim_grille,int rang_x, int rang_y,char grille[][dim_grille]){
    int ok;
    for (int i=rang_x; i>0; i--){
        for(int j= rang_y;j>0;j--){
            if(grille[rang_x][rang_y]==grille[i][j] && (i!= rang_x || j!= rang_y)){
                ok=1;
            }
        }
    }
    if (ok==1){
        return ok;
    }else{
        return 0;}
}



void remplissage_grille (int dim_grille,char grille[][dim_grille]){
    int ok;
    for (int x=0;x<dim_grille;x++){
        for(int y=0;y<dim_grille;y++){
            do{grille[x][y]=lettre_random();
                ok = unicite_lettre_3_3(dim_grille,x,y,grille);
            } while (ok==1);
        }
    }
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