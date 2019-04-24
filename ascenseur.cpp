#include "ascenseur.h"
#include "Parametres.h"

ascenseur::ascenseur(int numero, int etage, int destination, int etageMax)
    : numero_(numero), etage_(etage), destination_(destination), etageMax_(etageMax)
{
    file_ = new list<personne *>(0);
	tempsJusquaEtage_ = 0;
	estOccupe_ = false;
	estEnMouvement_ = false;
}

ascenseur::~ascenseur()
{
}

void ascenseur::majAscenseur(int seconde, vector<etage>* tabEtage, int & tempsAttenteTotale, int & nombrePassage)
{
	//Nous supposons ici le temps pour entrer et sortir de l'ascenceur instantannés
	if (tempsJusquaEtage_ == 0 && etage_ == destination_) //Donc si nous sommes à l'étage de destination de l'ascenceur
	{
		//Les personnes sortent de l'ascenseur
		sortir(seconde, &(*tabEtage)[getEtage()], tempsAttenteTotale, nombrePassage);
		//Les personnes entrent dans l'ascenseur
		entrer(&(*tabEtage)[getEtage()]);
		estEnMouvement_ = false;
	}
	if (!estEnMouvement_ || !estOccupe_)
	{
		//On choisit une nouvelle destination
		choisirDestination(tabEtage);
	}
	if (!estOccupe_)
	{
		//On choisit la destination à vide qu'on veut
		choisirDestinationVide();
	}
	if (estEnMouvement_)
	{
		//Déplacement des ascenceurs
		bouger();
	}
}

/**
 * L'ascenceur boouge d'un etage en direction de l'etage souhaite
 */
void ascenseur::bouger()
{
	if (tempsJusquaEtage_ > 0)
	{
		tempsJusquaEtage_--;
	}
	else if (etage_ < destination_)
	{
		etage_++;
		tempsJusquaEtage_ = TEMPS_ENTRE_DEUX_ETAGES;
	}
	else if (etage_ > destination_)
	{
		etage_--;
		tempsJusquaEtage_ = TEMPS_ENTRE_DEUX_ETAGES;
	}
	else
	{
		estEnMouvement_ = false;
	}
}

/**
 * Toutes les personnes de l'etage qui attendent l'ascenseur, y monte
 */
void ascenseur::entrer(etage *etage)
{
	for (list<personne *>::iterator it = etage->getQAscenseur()->getFile()->begin(); it != etage->getQAscenseur()->getFile()->end(); it++)
	{
		file_->push_back(*it);
	}
	etage->ViderQAscenseur();
}

/**
 * Toutes les personnes de l'ascenseur qui sont à leur étage descendent
 */
void ascenseur::sortir(int seconde, etage *etage, int &tempsAttenteTotale, int &nombrePassage)
{
    for (list<personne *>::iterator it = file_->begin(); it != file_->end(); it++)
    {
        //Les personnes qui souhaitent descendre a cet etage descendent
        //et les portes s'ouvrent a l'etage d'arrivee
        if ((*it)->getDestination() == destination_ && etage_ == destination_)
        {
            (*it)->setDepart(seconde);
            (*it)->setEtage(etage_);
            (*it)->setDestination(0);

            //Fonction pour faire des stats
            tempsAttenteTotale += (*it)->getDepart() - (*it)->getArrivee();
            nombrePassage++;

            //sort de la file de l'ascenseur pour celle de l'etage s'il n'est pas au rdc
			if (etage_ == 0)
			{
				personne* toErase = *it;
				if (it == file_->begin())
				{
					file_->erase(it);
					if (file_->empty())
						break;
					else
						it = file_->begin();
				}
				else
				{
					it--;
					list<personne *>::iterator itEffacer = it;
					itEffacer++;
					file_->erase(itEffacer);
				}
				delete toErase;
			}
			else
			{
				etage->getQAttente()->getFile()->push_back(*it);
				if (it == file_->begin())
				{
					file_->erase(it);
					if (file_->empty())
						break;
					else
						it = file_->begin();
				}
				else
				{
					it--;
					list<personne *>::iterator itEffacer = it;
					itEffacer++;
					file_->erase(itEffacer);
				}
			}
        }
    }
}

void ascenseur::firstComeFirstServe()
{
    list<personne *>::iterator it = file_->begin();
    destination_ = (*it)->getDestination();
}

void ascenseur::shortestSeekTimeFirst()
{
    list<personne *>::iterator it;
    for (it = file_->begin(); it != file_->end(); it++)
    {
        if (destination_ == etage_)
            destination_ = (*it)->getDestination();
        else if (std::abs((*it)->getDestination() - etage_) < std::abs(destination_ - etage_))
            destination_ = (*it)->getDestination();
    }
}

void ascenseur::firstComeFirstServe_Vide(vector<etage> *tabEtage)
{
	int tempsMin = -1;
	int etageMin = -1;
	for (int i = 0; i < tabEtage->size(); i++)
	{
		if ((*tabEtage)[i].getTempsPremierArrive() >= 0)
		{
			if (tempsMin < 0 || tempsMin > (*tabEtage)[i].getTempsPremierArrive())
			{
				tempsMin = (*tabEtage)[i].getTempsPremierArrive();
				etageMin = i;
			}
		}
	}
	estOccupe_ = etageMin > -1;
	if (estOccupe_)
	{
		destination_ = etageMin;
	}
}

void ascenseur::shortestSeekTimeFirst_Vide(vector<etage> *tabEtage)
{
	int plusProcheDescendant = -1;
	int valeurDescente = -1;
	int i = 1;
	while(plusProcheDescendant == -1 && i <= etage_)
	{
		if (!(*tabEtage)[etage_ - i].getQAscenseur()->getFile()->empty())
		{
			plusProcheDescendant = etage_ - i;
			valeurDescente = i;
		}
		i++;
	}
	int plusProcheMontant = -1;
	int valeurMontee = -1;
	i = 1;
	while (plusProcheMontant == -1 && i <= etageMax_ - etage_)
	{
		if (!(*tabEtage)[etage_ + i].getQAscenseur()->getFile()->empty())
		{
			plusProcheMontant = etage_ + i;
			valeurMontee = i;
		}
		i++;
	}
	if (plusProcheDescendant > -1)
	{
		estOccupe_ = true;
		if (plusProcheMontant > -1)
		{
			destination_ = valeurDescente > valeurMontee ? plusProcheMontant : plusProcheDescendant;
		}
		else
		{
			destination_ = plusProcheDescendant;
		}
	}
	else if (plusProcheMontant > -1)
	{
		estOccupe_ = true;
		destination_ = plusProcheMontant;
	}
	else
	{
		estOccupe_ = false;
	}
}

/**
 * L'ascenseur choisit sa destination 
 */
void ascenseur::choisirDestination(vector<etage> *tabEtage)
{

    //Plus de passager dans l'ascensseur
    //l'ascenceur va là où il y a de la demande
    //en traitant en priorite le bas
    //si personne, il reste la ou il est
    if (file_->empty())
    {
#ifdef FCFS
		//First-Come First-Serve
		firstComeFirstServe_Vide(tabEtage);
#else
		// Shortest-Seek-Time-First
		shortestSeekTimeFirst_Vide(tabEtage);
#endif
    }
    else
    {
		estOccupe_ = true;
#ifdef FCFS
		//First-Come First-Serve
		firstComeFirstServe();
#else
		// Shortest-Seek-Time-First
		shortestSeekTimeFirst();
#endif
    }
	estEnMouvement_ = destination_ != etage_;
}

void ascenseur::choisirDestinationVide()
{
#ifdef IDLESTAY
	destination_ = etage_;
	estEnMouvement_ = tempsJusquaEtage_ != 0;
#else
#ifdef IDLEMIDDLE
	destination_ = etageMax_ / 2;
	estEnMouvement_ = etage_ != destination_ || tempsJusquaEtage_ != 0;
#else
#ifdef IDLEBOTTOM
	destination_ = 0;
	estEnMouvement_ = etage_ != destination_ || tempsJusquaEtage_ != 0;
#endif
#endif
#endif
}

/**
 * Fonction d'affichage d'ascenseur
 */
void ascenseur::afficher()
{
	std::cout << "Ascenseur #" << numero_ << "\tEtage : " << etage_ << "\tDestination : " << destination_ << "\tEtage Max : " << etageMax_ << std::endl;
    for (list<personne *>::iterator it = file_->begin(); it != file_->end(); it++)
    {
        (*it)->afficher();
    }
	std::cout << std::endl;
}