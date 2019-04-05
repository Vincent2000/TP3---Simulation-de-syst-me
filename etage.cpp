#include "etage.h"

etage::etage(int numero)
    : numero_(numero)
{
    qAscenseur_ = new queue(numero_);
    qAttente_ = new queue(numero_);
}

etage::~etage()
{
    qAscenseur_->~queue();
    qAttente_->~queue();
}

/**
 * Les perssonnes qui ont termine leurs affaires a leur etage, change de file pour attendre l'ascenseur pour redescendre
 */
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
            qAttente_->getFile()->erase(it);
        }
    }
}

/**
 * Fonction d'affichage d'etage
 */
void etage::afficher()
{
    printf("Queue d'ascenseur #%d\t", numero_);
    qAscenseur_->afficher();
    printf("Queue d'attente #%d\t", numero_);
    qAttente_->afficher();
}
