//
// Created by enora on 16/05/2022.
//

#ifndef MAIN_C_PROJET_H
#define MAIN_C_PROJET_H



typedef struct {
    int x;
    int y;
}structure_position;

typedef struct  {
    char lettre;
    structure_position position;
}structure_lettre;

void recherche_premiere_lettre (int compteur,int dim_grille,char grille[][dim_grille],char mot[],structure_lettre position_prem_lettre[]);
int verif_lien_entre_lettres(int compteur,int dim_grille,char grille[][dim_grille],char mot[],structure_lettre position_prem_lettre[]);

int menu_principal();

int menu_scores();

char lettre_random ();

void duree_partie(int duree);

#endif //MAIN_C_PROJET_H
