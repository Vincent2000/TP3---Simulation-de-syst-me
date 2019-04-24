#ifndef PARAMETRES_H
#define PARAMETRES_H

#define VERBEUX //A d�commenter si vous voulez le d�tail de chaque jour

#define N 1
#define F 7
#define NOMBRE_JOURS 10 //Nombres de jours de simulation
#define HEURES_PAR_JOUR 10 //Nombres d'heures o� le syst�me est actif dans une journ�e
#define LAMBDA_ARRIVEE 0.5 //taux moyen d'arriv�e global en personnes par minute
#define MOYENNE_TEMPS_TRAVAIL 3600 //En secondes
#define TEMPS_ENTRE_DEUX_ETAGES 10 //Nombre de secondes que met un ascenceur � se d�placer entre deux �tages successifs

//Une et une seule des deux lignes suivantes doit �tre comment�e
//#define FCFS //Les ascenseurs fonctionneront de mani�re First-Come-First-Serve
#define SSTF //Les ascenseurs fonctionneront de mani�re Shortest-Seek-Time-First

//Deux des trois lignes suivantes doivent �tre comment�es pour choisir le comportement des ascenceurs � vide
//#define IDLESTAY
#define IDLEBOTTOM
//#define IDLEMIDDLE

#endif