#include "queue.h"

queue::queue(int numero) : numero_(numero)
{
    file_ = new list<personne *>(0);
}

queue::~queue()
{
}

void queue::afficher()
{
    // printf("taille : %d\n", file_->size());
    printf("\n");
    list<personne*>::iterator it;
    for (it=file_->begin(); it != file_->end(); it++)
    {
        (*it)->afficher();
    }
    printf("\n");
}
