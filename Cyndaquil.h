#ifndef CYNDAQUIL_H
#define CYNDAQUIL_H
#include "Fuego.h"
#include "Movida.h"
#include <string>
using std::string;

class Cyndaquil:public Fuego{
public:
	Cyndaquil();
	Cyndaquil(const Cyndaquil&);
	~Cyndaquil();
	virtual Movida hiddenSkill(int);
};

#endif /*CYNDAQUIL_H*/
