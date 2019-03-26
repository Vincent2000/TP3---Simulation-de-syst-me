#ifndef ascenseur_H
#define ascenseur_H

class ascenseur
{
  private:
    int numero_;
    int etage_;
    int etageMax_;

  public:
    ascenseur(int numero, int etage, int etageMax);
    ~ascenseur();
    void afficher();
};

#endif