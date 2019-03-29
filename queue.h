#ifndef QUEUE_H
#define QUEUE_H

#include <cstdio>
#include <vector>
#include "personne.h"

using namespace std;

class queue
{
private:
	int numero_;
	vector<personne *> *file_;

public:
	queue(int numero = -1);
	~queue();
	void afficher();

	//Getters
	vector<personne *> *getFile() { return file_; }
	//Setters
	void setFile(vector<personne *> *file) { file_ = file; }
};

#endif