#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "ville.h"
#include "gaule.h"

typedef struct {
    Liste_Gaule *ville_suivante;
    Liste_Gaule *ville_precedente;
    Ville *ville;
}Liste_Gaule;

struct Gaule_t{
    Liste_Gaule *premiere_ville;
    Liste_Gaule *derniere_ville;
    int nombre_villes;
    int est_circuit;
    int nombre_specialite;
};



Static Liste_Gaule *cree_Liste_Gaule(Ville *ville);

Static Liste_Gaule *cree_Liste_Gaule(Ville *ville){
    assert(ville!=NULL);

    Liste_Gaule *liste = malloc(sizeof(Liste_Gaule));
    if(liste==NULL)
        return NULL;

    liste->ville = Ville;

    return liste;
}

Gaule *cree_nouveau_tour(Ville *ville1, Ville *ville2){

}

