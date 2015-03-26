#ifndef CHIKORITA_H
#define CHIKORITA_H
#include "Grama.h"
#include "Movida.h"
#include <string>
using std::string;

class Chikorita:public Grama{
public:
	Chikorita();
	Chikorita(const Chikorita&);
	~Chikorita();
	virtual Movida hiddenSkill(int);
};

#endif /*CHIKORITA_H*/
