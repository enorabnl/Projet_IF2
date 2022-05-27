//
// Created by enora on 25/05/2022.
//

#ifndef MAIN_C_CREATION_PARTIES_H
#define MAIN_C_CREATION_PARTIES_H
void duree_partie(int duree);
char lettre_random ();
int unicite_lettre_3_3 (int dim_grille,int rang_x, int rang_y,char grille[][dim_grille]);
void remplissage_grille (int zone_x, int zone_y, int dim_grille,char grille[][dim_grille]);
void deplacement_zone_3_3 (int dim_grille,char grille[][dim_grille]);
void affichage_grille (int dimension_grille, char grille[][dimension_grille]);
void reset_grille (int dim_grille, char grille[][dim_grille]);


#endif //MAIN_C_CREATION_PARTIES_H
