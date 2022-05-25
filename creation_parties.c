//
// Created by enora on 25/05/2022.
//

#include "creation_parties.h"
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
    for (int i=rang_x; i>rang_x -3; i--){
        for(int j= rang_y;j>rang_y -3;j--){
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