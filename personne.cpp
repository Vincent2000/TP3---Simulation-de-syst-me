#include "personne.h"

personne::personne(int numero, int arrivee, int depart, int destination, int etage, int tempsAttente)
    : numero_(numero), arrivee_(arrivee), depart_(depart), destination_(destination), etage_(etage), tempsAttente_(tempsAttente)
{
}

personne::~personne()
{
}

/**
 * Fonction d'affichage de personne
 */
void personne::afficher()
{
    printf("Personne #%d\tArrivee : %d\tDepart : %d\tEtage: %d (%d)\tAttente : %d s\n", numero_, arrivee_, depart_, etage_, destination_, tempsAttente_);
}
