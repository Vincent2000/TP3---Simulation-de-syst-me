#include "personne.h"
#include "Parametres.h"

personne::personne(int numero, int arrivee, int depart, int destination, int etage, int tempsAttente)
    : numero_(numero), arrivee_(arrivee), depart_(depart), destination_(destination), etage_(etage), tempsAttente_(tempsAttente)
{
}

personne::~personne()
{
}

/**
 * Fonction d'affichage de personne
 */
void personne::afficher()
{
	std::cout << "Personne #" << numero_ << "\tArrivee : " << arrivee_ << "\tDepart :" << depart_ << "\tEtage: " << etage_ << " (" << destination_ << ")\tAttente : " << tempsAttente_ << " s" << std::endl;
}
