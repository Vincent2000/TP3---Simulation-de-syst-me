#include "ascenseur.h"

ascenseur::ascenseur(int numero, int etage, int destination, int etageMax)
    : numero_(numero), etage_(etage), destination_(destination), etageMax_(etageMax)
{
    file_ = new list<personne *>(0);
}

ascenseur::~ascenseur()
{
}

/**
 * L'ascenceur boouge d'un etage en direction de l'etage souhaite
 */
void ascenseur::bouger()
{
    if (etage_ < destination_)
        etage_++;
    else if (etage_ > destination_)
        etage_--;
}

/**
 * Toutes les personnes de l'etage qui attendent l'ascenseur, y monte
 */
void ascenseur::entrer(etage *etage)
{
    file_->merge(*(etage->getQAscenseur()->getFile()));
}

/**
 * Toutes les personnes de l'ascenseur qui attendent l'ascenseur, y monte
 */
void ascenseur::sortir(int seconde, etage *etage)
{
    for (list<personne *>::iterator it = file_->begin(); it != file_->end(); it++)
    {
        //Les personnes qui souhaitent descendre a cet etage descendent
        //et les portes s'ouvrent a l'etage d'arrivee
        if ((*it)->getDestination() == destination_ && etage_ == destination_)
        {
            (*it)->setDepart(seconde);
            (*it)->setEtage(etage_);
            (*it)->setDestination(1);

            //Fonction pour faire des stats

            etage->getQAttente()->getFile()->push_back(*it);
            file_->erase(it);
        }
    }
}

void ascenseur::firstComeFirstServe()
{
    list<personne *>::iterator it = file_->begin();
    destination_ = (*it)->getDestination();
}

void ascenseur::shortestSeekTimeFirst()
{
    list<personne *>::iterator it;
    for (it = file_->begin(); it != file_->end(); it++)
    {
        if (destination_ == etage_)
            destination_ = (*it)->getDestination();
        else if (abs((*it)->getDestination() - etage_) < abs(destination_ - etage_))
            destination_ = (*it)->getDestination();
    }
}

/**
 * L'ascenseur choisit sa destination 
 */
void ascenseur::choisirDestination(vector<etage> *tabEtage)
{

    //Plus de passager dans l'ascensseur
    //l'ascenceur va là où il y a de la demande
    //en traitant en priorite le bas
    //si personne, il reste la ou il est
    if (file_->empty())
    {
        int i = 0;
        while (i < tabEtage->size() && (*tabEtage)[i].getQAscenseur()->getFile()->empty())
        {
            i++;
        }
        if (i < tabEtage->size())
        {
            destination_ = i + 1;
        }
    }
    else
    {
        //First-Come First-Serve
        // firstComeFirstServe();

        // Shortest-Seek-Time-First
        shortestSeekTimeFirst();
    }
}

/**
 * Fonction d'affichage d'ascenseur
 */
void ascenseur::afficher()
{
    printf("Ascenseur #%d\tEtage : %d\tDestination : %d\tEtage Max : %d\n", numero_, etage_, destination_, etageMax_);
    for (list<personne *>::iterator it = file_->begin(); it != file_->end(); it++)
    {
        (*it)->afficher();
    }
    printf("\n");
}