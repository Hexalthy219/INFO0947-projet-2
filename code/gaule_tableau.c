#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "ville.h"
#include "gaule.h"

struct Tour_Gaule_t{
    Ville **tableau_ville;
    int nombre_villes;
};

Tour_Gaule *cree_nouveau_tour(Ville *ville1, Ville *ville2){
    assert(ville1!=NULL && ville2!=NULL);

    Tour_Gaule *tour_gaule = malloc(sizeof(Tour_Gaule));
    if(tour_gaule==NULL)
        return NULL;

    tour_gaule->nombre_villes = 2;
    tour_gaule->tableau_ville = malloc(2*size_ville());
    if(tour_gaule->tableau_ville==NULL){
        free(tour_gaule);
        tour_gaule=NULL;
        return NULL;
    }
    tour_gaule->tableau_ville[0] = ville1;
    tour_gaule->tableau_ville[1] = ville2;

    return tour_gaule;
}

void detruit_tour(Tour_Gaule *tour){
    if(tour==NULL)
        return;
    
    if(tour->tableau_ville!=NULL){
        for(int i=0; i<tour->nombre_villes; i++)
            detruit_ville(tour->tableau_ville[i]);
        free(tour->tableau_ville);
        tour->tableau_ville = NULL;
    } 
    free(tour);
}

void set_nombre_villes(Tour_Gaule *tour, int nombre_villes){
    assert(nombre_villes>0 && tour!=NULL);

    tour->nombre_villes = nombre_villes;
}

int get_nombre_villes(Tour_Gaule *tour){
    assert(tour!=NULL);

    return tour->nombre_villes;
}

int ajoute_ville(Tour_Gaule *tour, Ville *ville){
    assert(ville!=NULL);

    set_nombre_villes(tour, get_nombre_villes(tour)+1);
    tour = realloc(tour, get_nombre_villes(tour)*size_ville());
    if(tour==NULL)
        return -1;

    return 0;
}
