#include <cstdio>
#include <vector>
#include "ascenseur.h"
#include "personne.h"
#include "queue.h"

int main(/*int argc, char const *argv[]*/)
{
    personne p1 = personne(1, 0, 10);
    personne p2 = personne(2, 0, 10);
    personne p3 = personne(3, 0, 10);

    p1.afficher();
    p2.afficher();
    p3.afficher();

    ascenseur a1 = ascenseur(1, 0, 5);
    ascenseur a2 = ascenseur(2, 0, 5);
    ascenseur a3 = ascenseur(3, 0, 5);

    a1.afficher();
    a2.afficher();
    a3.afficher();


    queue q1 = queue(1);
    q1.getFile()->push_back(p1);
    q1.getFile()->push_back(p2);
    q1.getFile()->push_back(p3);

    q1.afficher();
    
    printf("Hello, world !");
    return 0;
}
