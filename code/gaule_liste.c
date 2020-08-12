#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "ville.h"
#include "gaule.h"

struct Cellule_Gaule_t{
    Cellule_Gaule *cellule_suivante;
    Cellule_Gaule *cellule_precedente;
    Ville *ville;
};

struct Gaule_t{
    Cellule_Gaule *premiere_cellule;
    Cellule_Gaule *derniere_cellule;
    int nombre_villes;
    int est_circuit;
    int nombre_specialites;
};



static Cellule_Gaule *cree_Cellule_Gaule(Ville *ville, Cellule_Gaule *cellule_precedente, Cellule_Gaule *cellule_suivante);

static void detruit_liste(Cellule_Gaule *cellule);

static Cellule_Gaule *cree_Cellule_Gaule(Ville *ville, Cellule_Gaule *cellule_precedente, Cellule_Gaule *cellule_suivante){
    assert(ville!=NULL && cellule_precedente!=NULL && cellule_suivante!=NULL);

    Cellule_Gaule *liste = malloc(sizeof(Cellule_Gaule));
    if(liste==NULL)
        return NULL;

    liste->ville = ville;
    liste->cellule_precedente = cellule_precedente;
    liste->cellule_suivante = cellule_suivante;

    return liste;
}

static void detruit_liste(Cellule_Gaule *cellule){
    if(cellule!=NULL){
        if(cellule->cellule_suivante!=NULL)
            detruit_liste(cellule->cellule_suivante);
        free(cellule);
        cellule = NULL;
    }
}

Gaule *cree_nouveau_tour(Ville *ville1, Ville *ville2){
    assert(ville1!=NULL && ville2!=NULL && (compare_string(get_nom_ville(ville1), get_nom_ville(ville2))!=0));

    Gaule *tour = malloc(sizeof(Gaule));
    if (tour==NULL)
        return NULL;
    
    Cellule_Gaule *cellule1 = cree_Cellule_Gaule(ville1, NULL, NULL);
    if(cellule1==NULL){
        free(tour);
        return NULL;
    }
    Cellule_Gaule *cellule2 = cree_Cellule_Gaule(ville2, cellule1, NULL);
    if(cellule2==NULL){
        free(cellule1);
        free(tour);
    }
    cellule1->cellule_suivante = cellule2;

    tour->premiere_cellule = cellule1;
    tour->derniere_cellule = cellule2;
    tour->nombre_villes = 2;
    
    tour->nombre_specialites = 0;
    if (get_specialite_ville(ville1)!=NULL)
        tour->nombre_specialites++;
    if (get_specialite_ville(ville2)!=NULL)
        tour->nombre_specialites++;

    tour->est_circuit = 0;

    return tour;
}

void detruit_tour(Gaule *tour){
    if (tour==NULL)
        return;
    if(tour->premiere_cellule!=NULL)
        detruit_liste(tour->premiere_cellule);
    free(tour);
}

void set_nombre_villes(Gaule *tour, int nombre_villes) {
    assert(nombre_villes>0 && tour!=NULL);

    tour->nombre_villes = nombre_villes;
}

int get_nombre_villes(Gaule *tour) {
    assert(tour!=NULL);

    return tour->nombre_villes;
}

int ajoute_ville(Gaule *tour, Ville *ville){
    assert(tour!=NULL && ville!=NULL);

    char *nom=get_nom_ville(ville);

    //Vérifie que l'on ne rajoute pas la même ville que la dernière de la liste
    if(!compare_string(get_nom_ville(tour->derniere_cellule->ville), nom))
        return -1;

    //Création et ajout de la nouvelle cellule, contenant la nouvelle ville, à la liste
    set_nombre_villes(tour, get_nombre_villes(tour)+1);
    Cellule_Gaule *nouvelle_cellule = cree_Cellule_Gaule(ville, tour->derniere_cellule, NULL);
    if (nouvelle_cellule==NULL)
        return -1;
    
    tour->derniere_cellule->cellule_suivante = nouvelle_cellule;
    
    //maj du nombre de spécialités
    if(get_specialite_ville(ville)!=NULL){
        if(!ville_en_double(tour, get_nom_ville(ville)))
            tour->nombre_specialites++;
    }   

    maj_est_circuit(tour);

    return 0;
}

void supprime_ville(Gaule *tour){
    assert(tour!=NULL && tour->nombre_villes>2);

    //si la derniere ville du tour n'était pas en double, alors décrémente le nombre de spécialité de 1
    if(get_specialite_ville(tour->derniere_cellule->ville)!=NULL){
        if(!ville_en_double(tour, get_nom_ville(tour->derniere_cellule->ville)))
            tour->nombre_specialites--;
    }

    //libère la dernière cellule et mets à jour le pointeur de dernière cellule sur celle précédant la cellule retirée
    Cellule_Gaule *nouvelle_derniere_cellule = tour->derniere_cellule->cellule_precedente;
    detruit_liste(tour->derniere_cellule);
    nouvelle_derniere_cellule->cellule_suivante = NULL;
    tour->derniere_cellule = nouvelle_derniere_cellule;


    maj_est_circuit(tour);
}

void maj_est_circuit(Gaule *tour){
    assert(tour!=NULL);

    tour->est_circuit = 0;
    if(tour-> nombre_villes<=2 || compare_string(get_nom_ville(tour->premiere_cellule->ville),get_nom_ville(tour->derniere_cellule->ville))!=0){
         return;
    }

    tour->est_circuit = 1;
}

int get_est_circuit(Gaule *tour){
    assert(tour!=NULL);

    return tour->est_circuit;
}

int get_nombre_specialites(Gaule *tour){
    assert(tour!=NULL);

    return tour->nombre_specialites;
}

char *get_specialite(Gaule *tour, char *nom_ville){
    assert(tour!=NULL && nom_ville!=NULL);

    Cellule_Gaule *recherche_cellule = tour->premiere_cellule;
    while(compare_string(nom_ville, get_nom_ville(recherche_cellule->ville))!=0 || recherche_cellule->cellule_suivante==NULL){
        recherche_cellule = recherche_cellule->cellule_suivante;
    }
    if(recherche_cellule==NULL)
        return NULL;
    
    return get_specialite_ville(recherche_cellule->ville);
}

int compare_string(char *chaine1, char *chaine2){
    int i=0;
    while (chaine1[i]!=0) {
        if (chaine2[i] == 0 || (chaine1[i] != chaine2[i]))
            return -1;
        i++;
    }
    if (chaine2[i-1]!=0)
        return -1;
    return 0;
}

int ville_en_double(Gaule *tour, char *nom_ville){
    assert(tour!=NULL && nom_ville!=NULL);

    Cellule_Gaule *recherche_double = tour->premiere_cellule;
    int n_apparition=0;
    while(recherche_double!=NULL && n_apparition<2){
        if(compare_string(get_nom_ville(recherche_double->ville),nom_ville)==0)
            n_apparition++;
        recherche_double = recherche_double->cellule_suivante;
    }
    
    return n_apparition>=2;
}
