#include "seatest.h"
#include "ville.h"
#include "gaule.h"

#include <stdio.h>

static void test_ajoute_ville()
{
    Ville *v1 = creer_ville("Kos", 27.28889, 36.89333);
    Ville *v2 = creer_ville("Olbia", 9.48685, 40.9225);
    Ville *v3 = creer_ville("Brouwersdam", 3.860013, 51.766821);

    set_specialite_ville(v3, "Gouda, le seul truc qu'ils savent faire.");

    Gaule *tour = cree_nouveau_tour(v1, v2);

    ajoute_ville(tour, v3);

    assert_string_equal("Gouda, le seul truc qu'ils savent faire.", get_specialite(tour, "Brouwersdam"));
    assert_int_equal(0, get_est_circuit(tour));

    ajoute_ville(tour, v1);
    assert_int_equal(1, get_est_circuit(tour));

    detruit_tour(tour);
    detruit_ville(v1);
    detruit_ville(v2);
    detruit_ville(v3);
}

static void test_nombre_ville()
{
    Ville *v1 = creer_ville("Kos", 27.28889, 36.89333);
    Ville *v2 = creer_ville("Olbia", 9.48685, 40.9225);

    Gaule *tour = cree_nouveau_tour(v1, v2);

    assert_int_equal(2, get_nombre_villes(tour));
    ajoute_ville(tour, v1);
    assert_int_equal(3, get_nombre_villes(tour));
    supprime_ville(tour);
    assert_int_equal(2, get_nombre_villes(tour));

    detruit_tour(tour);
    detruit_ville(v1);
    detruit_ville(v2);
}

static void test_fixture()
{
    test_fixture_start();

    run_test(test_nombre_ville);
    run_test(test_ajoute_ville);

    test_fixture_end();
}

static void all_tests()
{
    test_fixture();
}

int main()
{
    return run_tests(all_tests);
}
