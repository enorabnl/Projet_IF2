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

typedef struct {
    char nom[20];
    int score;
    int temps;
    int dimension_grille;
}utilisateur;

void recherche_premiere_lettre (int compteur,int dim_grille,char grille[][dim_grille],char mot[],structure_lettre position_prem_lettre[]);
int verif_lien_entre_lettres(int compteur,int dim_grille,char grille[][dim_grille],char mot[],structure_lettre position_prem_lettre[]);
void tri_score(int j ,utilisateur joueur[j]);
void affichage(int j,utilisateur joueur[j]);
int verif_mot_francais();
void fin_de_partie(int j, utilisateur joueur[j]);



#endif //MAIN_C_PROJET_H
