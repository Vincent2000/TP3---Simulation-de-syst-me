#include "queue.h"
#include "Parametres.h"

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
	std::cout << std::endl;
    list<personne *>::iterator it;
    for (it = file_->begin(); it != file_->end(); it++)
    {
        (*it)->afficher();
    }
	std::cout << std::endl;
}
