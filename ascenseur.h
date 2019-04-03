#ifndef ascenseur_H
#define ascenseur_H

#include <cstdio>
#include <list>
#include <vector>
#include "queue.h"
#include "personne.h"
#include "etage.h"

using namespace std;

class ascenseur
{
private:
  int numero_;
  int etage_;
  int destination_;
  int etageMax_;
  list<personne *> *file_;

public:
  ascenseur(int numero = -1, int etage = -1, int destination = -1, int etageMax = -1);
  ~ascenseur();
  
  void bouger();
  void entrer(etage *etage);
  void sortir(int seconde, etage *etage);
  void choisirDestination(vector<etage> *tabEtage);
  void afficher();

  //Getters
  list<personne *> *getFile() { return file_; }
  int getEtage() { return etage_; }

  //Setters
  // void setDestination(int destination) { destination_ = destination; }
  // void setFile(list<personne *> *file) { file_ = file; }
};

#endif