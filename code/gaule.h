#ifndef _GAULE_
#define _GAULE_

typedef struct Cellule_Gaule_t Cellule_Gaule;

typedef struct Gaule_t Gaule;

Gaule *cree_nouveau_tour(Ville *ville1, Ville *ville2);

void detruit_tour(Gaule *tour);

void set_nombre_villes(Gaule *tour, int nombre_villes);

int get_nombre_villes(Gaule *tour);

int ajoute_ville(Gaule *tour, Ville *ville);

void supprime_ville(Gaule *tour);

int compare_string(char *chaine1, char *chaine2);

void maj_est_circuit(Gaule *tour);

int get_est_circuit(Gaule *tour);

int get_nombre_specialites(Gaule *tour);

#endif