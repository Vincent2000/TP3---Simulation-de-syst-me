#ifndef QUEUE_H
#define QUEUE_H

#include <cstdio>
#include <list>
#include "personne.h"

using namespace std;

class queue
{
  private:
	int numero_;
	list<personne *> *file_;

  public:
	queue(int numero = -1);
	~queue();
	void afficher();

	//Getters
	list<personne *> *getFile() { return file_; }
	//Setters
	void setFile(list<personne *> *file) { file_ = file; }
};

#endif