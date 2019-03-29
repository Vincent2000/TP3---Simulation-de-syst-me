#include "queue.h"

queue::queue(int numero) : numero_(numero)
{
    file_ = new vector<personne *>(0);
}

queue::~queue()
{
}

void queue::afficher()
{
    printf("taille : %d\n", file_->size());
    for (int i = 0; i < file_->size(); i++)
    {
        (*file_)[i]->afficher();
    }
    printf("\n");
}
