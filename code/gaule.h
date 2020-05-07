#ifndef _GAULE_
#define _GAULE_


typedef struct Tour_Gaule_t Tour_Gaule;

Tour_Gaule *cree_nouveau_tour(Ville *ville1, Ville *ville2);

void detruit_tour(Tour_Gaule *tour);

#endif