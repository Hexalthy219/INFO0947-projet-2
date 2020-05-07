#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "ville.h"
#include "gaule.h"

struct Tour_Gaule_t{
    Ville **tableau_ville;
    int nombre_ville;
};

Tour_Gaule *cree_nouveau_tour(Ville *ville1, Ville *ville2){
    assert(ville1!=NULL && ville2!=NULL);

    Tour_Gaule *tour_gaule = malloc(sizeof(Tour_Gaule));
    if(tour_gaule==NULL)
        return NULL;

    tour_gaule->nombre_ville = 2;
    tour_gaule->tableau_ville = malloc(2*sizeof(Ville));
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
        for(int i=0; i<tour->nombre_ville; i++)
            detruit_ville(tour->tableau_ville[i]);
        free(tour->tableau_ville);
        tour->tableau_ville = NULL;
    } 
    free(tour);
}



