#ifndef SQUIRTLE_H
#define SQUIRTLE_H
#include "Agua.h"
#include "Movida.h"
#include <string>
using std::string;

class Squirtle:public Agua{
public:
	Squirtle();
	Squirtle(const Squirtle&);
	~Squirtle();
	virtual string toString()const;
	virtual Movida hiddenSkill(int);
};

#endif /*SQUIRTLE_H*/