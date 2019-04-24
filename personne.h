#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>

class personne
{
private:
  int numero_;
  int arrivee_;      //Temps a l'arrivee à l'ascenceur et pression bouton
  int depart_;       //Temps a la sortie de l'ascenseur a l'etage souhaitee
  int etage_;        //Etage actuel
  int destination_;  //Etage auquel la personne veut se rendre
  int tempsAttente_; //Temps de travail a la destination

public:
  personne(int numero = -1, int arrivee = -1, int depart = -1, int destination = -1, int etage = -1, int tempsAttente = -1);
  ~personne();

  void decrementerTempsAttente() { tempsAttente_--; }
  void afficher();

  //Getters
  int getArrivee() { return arrivee_; }
  int getDepart() { return depart_; }
  int getDestination() { return destination_; }
  int getTempsAttente() { return tempsAttente_; }

  //Setters
  void setArrivee(int arrivee) { arrivee_ = arrivee; }
  void setDepart(int depart) { depart_ = depart; }
  void setEtage(int etage) { etage_ = etage; }
  void setDestination(int destination) { destination_ = destination; }
};

#endif