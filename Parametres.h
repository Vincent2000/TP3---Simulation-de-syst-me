#ifndef PARAMETRES_H
#define PARAMETRES_H

#define VERBEUX //A décommenter si vous voulez le détail de chaque jour

#define N 1
#define F 7
#define NOMBRE_JOURS 10 //Nombres de jours de simulation
#define HEURES_PAR_JOUR 10 //Nombres d'heures où le système est actif dans une journée
#define LAMBDA_ARRIVEE 0.5 //taux moyen d'arrivée global en personnes par minute
#define MOYENNE_TEMPS_TRAVAIL 3600 //En secondes
#define TEMPS_ENTRE_DEUX_ETAGES 10 //Nombre de secondes que met un ascenceur à se déplacer entre deux étages successifs

//Une et une seule des deux lignes suivantes doit être commentée
//#define FCFS //Les ascenseurs fonctionneront de manière First-Come-First-Serve
#define SSTF //Les ascenseurs fonctionneront de manière Shortest-Seek-Time-First

//Deux des trois lignes suivantes doivent être commentées pour choisir le comportement des ascenceurs à vide
//#define IDLESTAY
#define IDLEBOTTOM
//#define IDLEMIDDLE

#endif