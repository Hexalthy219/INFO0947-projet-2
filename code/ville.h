#ifndef _VILLE_
#define _VILLE_

typedef struct Ville_t Ville;

Ville *creer_ville(char *nom, int x, int y);

void detruit_ville(Ville *ville);

int get_x_ville(Ville *ville);

int get_y_ville(Ville *ville);

char *get_nom_ville(Ville *ville);

char *get_specialite_ville(Ville *ville);

void set_specialite_ville(Ville *ville, char *specialite);

double distance_entre_2_villes(Ville *ville1, Ville *ville2);

#endif