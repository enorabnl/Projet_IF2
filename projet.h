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
void remplissage_grille (int dim_grille,char grille[][dim_grille]);
int unicite_lettre_3_3 (int dim_grille,int rang_x, int rang_y,char grille[][dim_grille]);

char lettre_random ();

void duree_partie(int duree);

#endif //MAIN_C_PROJET_H
