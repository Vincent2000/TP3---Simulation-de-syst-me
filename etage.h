#ifndef ETAGE_H
#define ETAGE_H

#include "queue.h"

class etage
{
private:
  int numero_;        //Numero de l'etage
  int tempsPremierArrive_; //Date depuis laquelle des personnes font la queue devant l'ascenceur
  queue *qAscenseur_; //Les personnes dans cette queue ont fini leurs affaires et attendent un ascenseur pour descendre
  queue *qAttente_;   //Les personnes dans cete queue font leurs affaires à l'étage

public:
  etage(int numero);
  ~etage();

  void addToQAscenseur(personne* pers, int seconde);
  void transferer(int seconde);
  void afficher();
  void ViderQAscenseur();

  //Getters
  queue *getQAscenseur() { return qAscenseur_; }
  queue *getQAttente() { return qAttente_; }
  int getTempsPremierArrive() { return tempsPremierArrive_; }
};

#endif