#include "personne.h"

personne::personne(int numero, int arrivee, int depart, int destination, int etage)
    : numero_(numero), arrivee_(arrivee), depart_(depart), destination_(destination), etage_(etage)
{
}

personne::~personne()
{
}

void personne::afficher()
{
    printf("Personne #%d\tArrivee : %d\tDepart : %d\tEtage: %d\tDestination : %d\n", numero_, arrivee_, depart_, etage_, destination_);
}
