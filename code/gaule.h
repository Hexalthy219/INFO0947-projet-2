#ifndef _GAULE_
#define _GAULE_


typedef struct Tour_Gaule_t Tour_Gaule;

Tour_Gaule *cree_nouveau_tour(Ville *ville1, Ville *ville2);

void detruit_tour(Tour_Gaule *tour);

void set_nombre_villes(Tour_Gaule *tour, int nombre_villes);

int get_nombre_villes(Tour_Gaule *tour);

int ajoute_ville(Tour_Gaule *tour, Ville *ville);

#endif