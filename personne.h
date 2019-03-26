#ifndef PERSONNE_H
#define PERSONNE_H

class personne
{
  private:
    int numero_;
    int arrivee_; //Arrivee à l'ascneceur et pression bouton
    int depart_;  //la personne est arrivee a l'etage souhaitee

  public:
    personne(int numero=0, int arrivee=0, int depart=0);
    ~personne();
    void afficher();

    //Getters
    int getArrivee() { return arrivee_; }
    int getDepart() { return depart_; }

    //Setters
    void setArrivee(int arrivee) { arrivee_ = arrivee; }
    void setDepart(int depart) { depart_ = depart; }
};

#endif