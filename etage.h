#ifndef ETAGE_H
#define ETAGE_H

#include "queue.h"

class etage
{
private:
  int numero_;
  queue *qAscenseur_; //Les personnes dans cette queue ont fini leurs affaires et attendent un ascenseur pour descendre
  queue *qAttente_;   //Les personnes dans cete queue font leurs affaires à l'étage

public:
  etage(int numero);
  ~etage();
  void transferer();
  void afficher();
  //Getters
  queue *getQAscenseur() { return qAscenseur_; }
  queue *getQAttente() { return qAttente_; }
};

#endif