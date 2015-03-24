#ifndef CHARMANDER_H
#define CHARMANDER_H
#include "Fuego.h"
#include "Movida.h"
#include <string>
using std::string;

class Charmander:public Fuego{
public:
	Charmander();
	Charmander(const Charmander&);
	~Charmander();
	virtual string toString()const;
	virtual Movida hiddenSkill(int);
};

#endif /*CHARMANDER_H*/