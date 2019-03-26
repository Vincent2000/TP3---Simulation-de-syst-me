#include <cstdio>
#include "ascenseur.h"

ascenseur::ascenseur(int numero, int etage, int etageMax) : numero_(numero), etage_(etage), etageMax_(etageMax)
{
}

ascenseur::~ascenseur()
{
}

void ascenseur::afficher()
{
    printf("Ascenseur #%d\tEtage : %d\tEtage Max : %d\n", numero_, etage_, etageMax_);
}