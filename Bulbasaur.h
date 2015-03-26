#ifndef BULBASAUR_H
#define BULBASAUR_H
#include "Grama.h"
#include "Movida.h"
#include <string>
using std::string;

class Bulbasaur:public Grama{
public:
	Bulbasaur();
	Bulbasaur(const Bulbasaur&);
	~Bulbasaur();
	virtual Movida hiddenSkill(int);
};

#endif /*BULBASAUR_H*/
