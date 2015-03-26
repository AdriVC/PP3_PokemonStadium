#ifndef GRAMA_H
#define GRAMA_H
#include "Pokemon.h"
#include "Movida.h"
#include <string>
using std::string;

class Grama:public Pokemon{
public:
    Grama(string,string,string);
	Grama(const Grama&);
	~Grama();
	virtual Movida attack(int);
	virtual Movida defend(int);
	virtual Movida hiddenSkill(int)=0;
};

#endif /*GRAMA_H*/
