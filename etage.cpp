#include "etage.h"
#include "Parametres.h"

etage::etage(int numero)
    : numero_(numero)
{
    qAscenseur_ = new queue(numero_);
    qAttente_ = new queue(numero_);
	tempsPremierArrive_ = -1;
}

etage::~etage()
{
    qAscenseur_->~queue();
    qAttente_->~queue();
}

/**
 * Les perssonnes qui ont termine leurs affaires a leur etage, change de file pour attendre l'ascenseur pour redescendre
 */
void etage::addToQAscenseur(personne * pers, int seconde)
{
	qAscenseur_->getFile()->push_back(pers);
	if (tempsPremierArrive_ < 0)
	{
		tempsPremierArrive_ = seconde;
	}
}

void etage::transferer(int seconde)
{
    list<personne *>::iterator it;
    for (it = qAttente_->getFile()->begin(); it != qAttente_->getFile()->end(); it++)
    {
        if ((*it)->getTempsAttente() <= 0)
        {
            (*it)->setArrivee(seconde);
            (*it)->setDepart(-1);
            qAscenseur_->getFile()->push_back(*it);

			if (it == qAttente_->getFile()->begin())
			{
				qAttente_->getFile()->erase(it);
				if (qAttente_->getFile()->empty())
					break;
				else
					it = qAttente_->getFile()->begin();
			}
			else
			{
				it--;
				list<personne *>::iterator itEffacer = it;
				itEffacer++;
				qAttente_->getFile()->erase(itEffacer);
			}

			if (tempsPremierArrive_ < 0)
			{
				tempsPremierArrive_ = seconde;
			}
        }
    }
}

/**
 * Fonction d'affichage d'etage
 */
void etage::afficher()
{
    std:cout << "Queue d'ascenseur #" << numero_ << "\t";
    qAscenseur_->afficher();
    std::cout << "Queue d'attente #" << numero_ << "\t";
    qAttente_->afficher();
}

void etage::ViderQAscenseur()
{
	tempsPremierArrive_ = -1; //Plus personne n'attend
	qAscenseur_->getFile()->clear();
}
