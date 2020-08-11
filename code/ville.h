#ifndef _VILLE_
#define _VILLE_

typedef struct Ville_t Ville;

Ville *creer_ville(char *nom, float x, float y);

void detruit_ville(Ville *ville);

float get_x_ville(Ville *ville);

float get_y_ville(Ville *ville);

char *get_nom_ville(Ville *ville);

char *get_specialite_ville(Ville *ville);

void set_specialite_ville(Ville *ville, char *specialite);

float distance_entre_2_villes(Ville *ville1, Ville *ville2);

int size_ville(void);

#endif