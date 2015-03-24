#ifndef FUEGO_H
#define FUEGO_H
#include "Pokemon.h"
#include "Movida.h"
#include <string>
using std::string;

class Fuego:public Pokemon{
public:
    Fuego(string,string,string);
	Fuego(const Fuego&);
	~Fuego();
	virtual string toString()const;
	virtual Movida attack(int);
	virtual Movida defend(int);
	virtual Movida hiddenSkill(int)=0;
};

#endif /*FUEGO_H*/
