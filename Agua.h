#ifndef AGUA_H
#define AGUA_H
#include "Pokemon.h"
#include "Movida.h"
#include <string>
using std::string;

class Agua:public Pokemon{
public:
    Agua(string,string,string);
	Agua(const Agua&);
	~Agua();
    virtual string getClass()const;
	virtual Movida attack(int);
	virtual Movida defend(int);
	virtual Movida hiddenSkill(int)=0;
};

#endif /*AGUA_H*/
