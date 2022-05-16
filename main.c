#include <stdio.h>
#include<string.h>

int main() {
    printf("Hello, World2\n");
    return 0;
}
void recherche_premiere_lettre (int dim_plateau,char plateau[][dim_plateau],char mot[]){
    int lettre_trouvee=0;

    for(int ligne_plateau=0;ligne_plateau<dim_plateau;ligne_plateau++){
        for(int colone_plateau=0;colone_plateau<dim_plateau;colone_plateau++){
            if(plateau[ligne_plateau][colone_plateau]==mot[0]){
                //on met dans tableau de double structure
            }
        }
    }
    /*
   for(int lettre_mot=0;lettre_mot<strlen(mot);lettre_mot++){ //On vérifie les lettres du mots une par une


          while(mot[lettre_mot]!=plateau[ligne_plateau][colone_plateau] && colone_plateau<dim_plateau){
               colone_plateau++;
           }
           if (mot[lettre_mot]!=plateau[ligne_plateau][colone_plateau]){
               lettre_trouvee=1;
           }else{
               ligne_plateau++;
           }
    }*/
}


typedef struct position{
    int x;
    int y;
};

typedef struct position_lettre {
    char lettre;
    struct position position;
};