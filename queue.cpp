#include "queue.h"

queue::queue(int numero) : numero_(numero)
{
    file_ = new list<personne *>(0);
}

queue::~queue()
{
}

/**
 * Fonction d'affichage de queue
 */
void queue::afficher()
{
    printf("\n");
    list<personne *>::iterator it;
    for (it = file_->begin(); it != file_->end(); it++)
    {
        (*it)->afficher();
    }
    printf("\n");
}
