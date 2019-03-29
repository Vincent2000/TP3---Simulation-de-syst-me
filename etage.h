#ifndef ETAGE_H
#define ETAGE_H

#include "queue.h"

class etage
{
  private:
    int numero_;
    queue *qAscenseur_;
    queue *qAttente_;

  public:
    etage(int numero);
    ~etage();
    void afficher();
    //Getters
    queue *getQAscenseur() { return qAscenseur_; }
    queue *getQAttente() { return qAttente_; }
};

#endif