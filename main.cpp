#include <cstdio>
#include <vector>
#include <list>
#include <ctime>
#include <math.h>
#include "ascenseur.h"
#include "personne.h"
#include "queue.h"
#include "etage.h"

using namespace std;

int main()
{
    int const N = 2;
    int const F = 7;

    //Creation des ascenseurs
    vector<ascenseur> tabAscenseur;
    ascenseur a;
    for (int i = 0; i < N; i++)
    {
        a = ascenseur(i + 1, 1, 3, F);
        a.choisirDestination();
        tabAscenseur.push_back(a);
    }

    //Creation des étage avec 2 queues
    vector<etage> tabEtage;
    for (int i = 0; i < F; i++)
    {
        tabEtage.push_back(etage(i + 1));
    }

    std::clock_t start;
    double duration;
    start = std::clock();

    int seconde = 0;
    int numero_personne = 0;
    bool actionAjoutPersonne = false;
    bool actionAscenseur = false;
    bool actionAffichage = false;

    printf("\n\n");
    printf("**********************************\n");
    printf("****  Debut de la simulation  ****\n");
    printf("**********************************\n");
    printf("\n\n");
    while (true)
    {
        duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
        if (duration - seconde > 1)
        {
            seconde++;
            printf("%d ", seconde);
            actionAjoutPersonne = true;
            actionAscenseur = true;
            actionAffichage = true;
        }

        //Une personne arrive toutes les 30s à l'étage du dessous
        if (seconde % 3 == 0 && actionAjoutPersonne)
        {
            tabEtage[0].getQAscenseur()->getFile()->push_back((new personne(numero_personne, seconde, -1, rand() % F + 1, 1)));
            numero_personne++;
            actionAjoutPersonne = false;
        }

        if (seconde % 3 == 0 && seconde > 9 && actionAscenseur)
        {
            for (int i = 0; i < tabAscenseur.size(); i++)
            {
                //Les personnes sortent de l'ascenseur
                tabAscenseur[i].sortir(seconde, tabEtage[tabAscenseur[i].getEtage() - 1].getQAttente());
                //Les personnes entrent dans l'ascenceur
                tabAscenseur[i].entrer(tabEtage[tabAscenseur[i].getEtage() - 1].getQAscenseur());
                //Choix destination des ascenseurs
                tabAscenseur[i].choisirDestination();
                //Déplacement des ascenceurs
                tabAscenseur[i].bouger();
            }
            actionAscenseur = false;
        }

        if (seconde % 1 == 0 && actionAffichage)
        {
            //Affichage des ascenseurs
            printf("\n\n");
            for (int i = 0; i < tabAscenseur.size(); i++)
            {
                tabAscenseur[i].afficher();
            }
            //Affichage des queues
            for (int i = 0; i < tabEtage.size(); i++)
            {
                tabEtage[i].afficher();
            }
            actionAffichage = false;
        }
    }

    printf("Hello, world !\n");
    return 0;
}
