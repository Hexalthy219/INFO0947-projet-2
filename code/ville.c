#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "ville.h"

struct Ville_t{
    char *nom;
    float x;
    float y;
    char *specialite;
};

Ville *creer_ville(char *nom, float x, float y){
    assert(nom!=NULL);

    Ville *ville = malloc(sizeof(Ville));
    if(ville==NULL)
        return NULL;
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

float get_x_ville(Ville *ville){
    assert(ville != NULL);

    return ville->x;
}

float get_y_ville(Ville *ville){
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
    assert(ville!=NULL && specialite!=NULL);
    ville->specialite = specialite;
}

float distance_entre_2_villes(Ville *ville1, Ville *ville2){
    assert(ville1!=NULL && ville2!=NULL);

    return sqrt(pow(ville2->x - ville1->x, 2) + pow(ville2->y - ville1->y, 2));
}

int size_ville(void){
    return sizeof(Ville);
}