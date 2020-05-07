#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "ville.h"

struct Ville_t{
    char *nom;
    int x;
    int y;
    char *specialite;
};

Ville *creer_ville(char *nom, int x, int y){
    Ville *ville = malloc(sizeof(Ville));
    ville->nom = nom;
    ville->x = x;
    ville->y = y;

    return ville;
}

void detruit_ville(Ville *ville){
    if(ville!=NULL){
        free(ville);
        ville=NULL;
    }
}

int get_x_ville(Ville *ville){
    assert(ville != NULL);

    return ville->x;
}

int get_y_ville(Ville *ville){
    assert(ville != NULL);

    return ville->y;
}

char *get_nom_ville(Ville *ville){
    assert(ville!=NULL);

    return ville->nom;
}

char *get_specialite_ville(Ville *ville){
    assert(ville != NULL);

    return ville->specialite;
}

void set_specialite_ville(Ville *ville, char *specialite){
    ville->specialite = specialite;
}

double distance_entre_2_villes(Ville *ville1, Ville *ville2){
    return sqrt(pow(ville2->x - ville1->x, 2) + pow(ville2->y - ville1->y, 2));
}