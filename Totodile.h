#ifndef TOTODILE_H
#define TOTODILE_H
#include "Agua.h"
#include "Movida.h"
#include <string>
using std::string;

class Totodile:public Agua{
public:
	Totodile();
	Totodile(const Totodile&);
	~Totodile();
	virtual Movida hiddenSkill(int);
};

#endif /*TOTODILE_H*/
