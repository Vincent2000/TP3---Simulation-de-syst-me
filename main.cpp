#include <cstdio>
#include <vector>
#include <list>
#include <cmath>
#include <random>
#include <time.h>
#include "ascenseur.h"
#include "personne.h"
#include "queue.h"
#include "etage.h"
#include "Parametres.h"

using namespace std;

int main()
{
	std::cout << "**********************************" << std::endl;
	std::cout << "****  Debut de la simulation  ****" << std::endl;
	std::cout << "**********************************" << std::endl;
	std::cout << std::endl << std::endl;

#ifdef VERBEUX
	std::cout << " Journee |  nombre de passages | temps de reponse percu moyen" << std::endl;
#endif // VERBEUX

	float tempsPercuMoyenPlusieursJours = 0;

	for (int i = 0; i < NOMBRE_JOURS; i++)
	{
		srand(time(NULL));

		//Creation des etages avec 2 queues
		vector<etage> tabEtage;
		for (int i = 0; i < F; i++)
		{
			tabEtage.push_back(etage(i));
		}

		//Creation des ascenseurs
		vector<ascenseur> tabAscenseur;
		ascenseur a;
		for (int i = 0; i < N; i++)
		{
			a = ascenseur(i, 0, 0, F - 1);
			a.choisirDestination(&tabEtage);
			tabAscenseur.push_back(a);
		}

		int seconde = 0;
		int numero_personne = 0;
		int tempsAttenteTotale = 0;
		int nombrePassage = 0;

		default_random_engine gen(time(NULL));
		exponential_distribution<> distribExp(1. / MOYENNE_TEMPS_TRAVAIL);

		while (seconde < 3600 * HEURES_PAR_JOUR)
		{
			seconde++;

			//On regarde si quelqu'un arrive à ce moment là
			if (((float)rand() / (RAND_MAX)) < (float)LAMBDA_ARRIVEE / 60)
			{
				tabEtage[0].addToQAscenseur(new personne(numero_personne, seconde, -1, rand() % (F - 1) + 1, 1, (int)distribExp(gen)), seconde);
				numero_personne++;
			}

			//Maj ascenseurs
			for (int i = 0; i < tabAscenseur.size(); i++)
			{
				tabAscenseur[i].majAscenseur(seconde, &tabEtage, tempsAttenteTotale, nombrePassage);
			}

			//On met à jour les personnes dans le batiments
			list<personne *>::iterator it;
			for (int i = 1; i < tabEtage.size(); i++)
			{
				for (it = tabEtage[i].getQAttente()->getFile()->begin(); it != tabEtage[i].getQAttente()->getFile()->end(); it++)
				{
					(*it)->decrementerTempsAttente();
				}
				tabEtage[i].transferer(seconde);
			}
		}
#ifdef VERBEUX
		std::cout << "    " << i << "    |        " << nombrePassage << "         |    " << tempsAttenteTotale * 1. / nombrePassage << "s" << std::endl;
#endif // VERBEUX

		tempsPercuMoyenPlusieursJours += tempsAttenteTotale * 1. / nombrePassage;
	}
	tempsPercuMoyenPlusieursJours /= NOMBRE_JOURS;
	std::cout << std::endl << "Temps Percu Moyen sur toute la periode : " << tempsPercuMoyenPlusieursJours << "s" << std::endl;
	return 0;
}
