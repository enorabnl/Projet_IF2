//
// Created by enora on 25/05/2022.
//

#include "creation_parties.h"
#include "projet.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>

void duree_partie(int duree){
    do{
        printf("Combien de temps voulez-vous jouer (60s mini 180s maxi)");
        scanf("%d",&duree);
    }while(duree<60 || duree>180);
}


char lettre_random() {
    char lettre;
    int long nb;

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
        default: printf("erreur");
    }
    printf("%c",lettre);
    return lettre;
}


// Parce que la fonction lettre random avec les proba prend trop de temps
char lettre_random2() {

    char lettre;
    int nb;
    nb = rand() % 26;

    switch(nb){
        case 0 : lettre = 'A'; break;
        case 1 : lettre = 'B';break;
        case 2 : lettre ='C';break;
        case 3 : lettre = 'D';break;
        case 4 : lettre = 'E';break;
        case 5 : lettre = 'F';break;
        case 6 : lettre = 'G';break;
        case 7 : lettre = 'H';break;
        case 8 : lettre = 'I';break;
        case 9 : lettre = 'J';break;
        case 10 : lettre = 'K';break;
        case 11 : lettre = 'L';break;
        case 12 : lettre = 'M';break;
        case 13 : lettre = 'N';break;
        case 14 : lettre = 'O';break;
        case 15 : lettre = 'P';break;
        case 16 : lettre = 'Q';break;
        case 17 : lettre = 'R';break;
        case 18 : lettre = 'S';break;
        case 19 : lettre = 'T';break;
        case 20 : lettre = 'U';break;
        case 21 : lettre = 'V';break;
        case 22 : lettre = 'W';break;
        case 23 : lettre = 'X';break;
        case 24 : lettre = 'Y';break;
        case 25 : lettre = 'Z';break;
        default:
            printf("erreur");
    }
    return lettre;
}

int unicite_lettre_3_3 (int dim_grille,int zone_x, int zone_y,char grille[][dim_grille], char lettre_ref){
    int ok =0;
    int i=zone_x;
    int j=zone_y;


    do{
        if(grille[i][j]==lettre_ref){
            ok=1;
        }

        if(j>=(zone_y+2)){
            j=zone_y;
            i++;
        } else{
            j++;
        }

    } while (i<(zone_x+3)&&ok!=1);

    return ok;
}


void remplissage_grille (int zone_x, int zone_y, int dim_grille,char grille[][dim_grille]){
    char lettre_rand;
    structure_lettre lettre_ref;
    for (int x=zone_x;x<zone_x+3;x++){
        for(int y=zone_y;y<zone_y+3;y++){
            if (grille[x][y]==' '){
                do{
                    lettre_rand=lettre_random();
                } while (unicite_lettre_3_3(dim_grille,zone_x,zone_y,grille, lettre_rand)==1);
                grille[x][y]=lettre_rand;
                printf("%c\n",lettre_rand);
            }
        }
    }
}

void deplacement_zone_3_3 (int dim_grille,char grille[][dim_grille]){
    for (int zone_x=0;zone_x<dim_grille-2;zone_x++){
        for (int zone_y=0;zone_y<dim_grille-2;zone_y++){
            remplissage_grille(zone_x,zone_y,dim_grille,grille);
        }
    }
}


void affichage_grille (int dimension_grille, char grille[][dimension_grille]){
    for(int i=0 ; i<dimension_grille ; i++){
        for(int j=0 ; j<dimension_grille ; j++){
            printf(" %c |",grille[i][j]);
        }
        printf("\n");
    }
}

void reset_grille (int dim_grille, char grille[][dim_grille]){
    for (int x=0; x<dim_grille;x++){
        for (int y=0;y<dim_grille;y++){
            grille[x][y]=' ';
        }
    }
}
