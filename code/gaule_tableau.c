#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "ville.h"
#include "gaule.h"

struct Gaule_t{
    Ville **tableau_ville;
    int nombre_villes;
    int est_circuit;
    int nombre_specialites;
};

Gaule *cree_nouveau_tour(Ville *ville1, Ville *ville2){
    assert(ville1!=NULL && ville2!=NULL && (compare_string(get_nom_ville(ville1), get_nom_ville(ville2))!=0));
    
    Gaule *tour_gaule = malloc(sizeof(Gaule));
    if (tour_gaule==NULL)
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

    tour_gaule->nombre_specialites = 0;
    if(get_specialite_ville(ville1)!=NULL)
        tour_gaule->nombre_specialites++;
    if (get_specialite_ville(ville2)!=NULL)
        tour_gaule->nombre_specialites++;

    tour_gaule->est_circuit = 0;

    return tour_gaule;
}

void detruit_tour(Gaule *tour){
    if(tour==NULL)
        return;
    
    if(tour->tableau_ville!=NULL){
        free(tour->tableau_ville);
        tour->tableau_ville = NULL;
    } 
    free(tour);
}

void set_nombre_villes(Gaule *tour, int nombre_villes){
    assert(nombre_villes>0 && tour!=NULL);

    tour->nombre_villes = nombre_villes;
}

int get_nombre_villes(Gaule *tour){
    assert(tour!=NULL);

    return tour->nombre_villes;
}

int ajoute_ville(Gaule *tour, Ville *ville){
    assert(tour!=NULL && ville!=NULL);

    char *nom=get_nom_ville(ville);

    //Vérifie que la ville à ajouter est différente de la dernière du tour
    if(!(compare_string(get_nom_ville(tour->tableau_ville[get_nombre_villes(tour)-1]), nom)==-1))
        return -1;


    set_nombre_villes(tour, get_nombre_villes(tour)+1);
    tour->tableau_ville = realloc(tour->tableau_ville, get_nombre_villes(tour)*size_ville());
    if(tour==NULL)
        return -1;

    tour->tableau_ville[get_nombre_villes(tour)-1] = ville;

    if(get_specialite_ville(tour->tableau_ville[get_nombre_villes(tour)-1])!=NULL){
        if(!ville_en_double(tour, nom))
            tour->nombre_specialites++;
    }
    maj_est_circuit(tour);

    return 0;
}

void supprime_ville(Gaule *tour){
    assert(tour!=NULL && tour->nombre_villes>0);

    if(get_specialite_ville(tour->tableau_ville[get_nombre_villes(tour)-1])!=NULL){
        if (!ville_en_double(tour, get_nom_ville(tour->tableau_ville[get_nombre_villes(tour)-1])))
            tour->nombre_specialites--;
    }

    set_nombre_villes(tour, get_nombre_villes(tour)-1);
    tour->tableau_ville = realloc(tour->tableau_ville, get_nombre_villes(tour)*size_ville());
    
    maj_est_circuit(tour);
    
}

int compare_string(char *chaine1, char *chaine2){
    int i=0;
    while(chaine1[i]!='\0'){
        if (chaine2[i]=='\0' || (chaine1[i]!=chaine2[i]))
            return -1;
        i++;
    }
    if(chaine2[i]!='\0')
        return -1;
    return 0;
}

void maj_est_circuit(Gaule *tour){
    assert(tour!=NULL);

    tour->est_circuit = 0;
    if(tour->nombre_villes<=2 || compare_string(get_nom_ville(tour->tableau_ville[0]),get_nom_ville(tour->tableau_ville[get_nombre_villes(tour)-1])))
        return;

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

    char *nom2;
    int ville_appartient_tour = 0, i = 0;

    
    //Vérifie que le nom donné correspond à une des villes du tour
    for(; i<get_nombre_villes(tour) && ville_appartient_tour==0; i++){
        nom2 = get_nom_ville(tour->tableau_ville[i]);
        if(!compare_string(nom_ville, nom2)){
            ville_appartient_tour = 1;
            i--;
        }
    }
    if(!ville_appartient_tour)
        return NULL;
    
    return get_specialite_ville(tour->tableau_ville[i]);
}

int ville_en_double(Gaule *tour, char *nom_ville){
    assert(tour!=NULL && nom_ville!=NULL);

    int n_apparition = 0;
    for(int i = 0; i<get_nombre_villes(tour) && n_apparition<2 ; i++){
        if(compare_string(get_nom_ville(tour->tableau_ville[i]), nom_ville)==0)
            n_apparition++;
    }
    
    return n_apparition>=2;
}
