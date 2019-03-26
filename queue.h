#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include "personne.h"

using namespace std;

class queue
{
  private:
	int numero_;
	vector<personne> * file_;

  public:
	queue(int numero);
	~queue();
	void afficher();

	//Getters
	vector<personne> * getFile() { return file_; }
};

#endif