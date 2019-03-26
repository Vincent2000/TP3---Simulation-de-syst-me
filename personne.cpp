#include <cstdio>
#include "personne.h"

personne::personne(int numero, int arrivee, int depart) : numero_(numero), arrivee_(arrivee), depart_(depart)
{
}

personne::~personne()
{
}

void personne::afficher()
{
    printf("Personne #%d\tArrivee : %d\tDepart : %d\n", numero_, arrivee_, depart_);
}

