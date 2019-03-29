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
 * L'ascenceur monte d'un etage en direction de l'étage souhaite
 */
void ascenseur::bouger()
{
    if (!file_->empty())
    {
        if (etage_ < destination_)
        {
            etage_++;
        }
        else if (etage_ > destination_)
        {
            etage_--;
        }
    }
}

/**
 * Les personnes qui souhaitent aller a cet etage monte dans l'ascenceur
 */
void ascenseur::entrer(queue *queue)
{
    for (int i = 0; i < queue->getFile()->size(); i++)
    {
        file_->push_back((*queue->getFile())[i]);
    }
    queue->setFile(new vector<personne *>(0));
}

/**
 * 
 */
void ascenseur::sortir(int seconde, queue *queue)
{
    for (list<personne *>::iterator it = file_->begin(); it != file_->end(); it++)
    {
        //Les personnes qui souhaitent descendre a cet etage descendent
        //et les portes s'ouvrent a l'etage d'arrivee
        if ((*it)->getDestination() == destination_ && etage_ == destination_)
        {
            (*it)->setDepart(seconde);
            queue->getFile()->push_back(*it);
            file_->erase(it);
        }
    }
}

void ascenseur::choisirDestination()
{
    //Balayage
    if (etage_ == 1)
        destination_ = 7;
    else if (etage_ == 7)
        destination_ = 1;
}

void ascenseur::afficher()
{
    printf("Ascenseur #%d\tEtage : %d\tDestination : %d\tEtage Max : %d\n", numero_, etage_, destination_, etageMax_);
    for (list<personne *>::iterator it = file_->begin(); it != file_->end(); it++)
    {
        (*it)->afficher();
    }
    printf("\n");
}