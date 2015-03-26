#include "Agua.h"
#include "Totodile.h"
#include "Movida.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Totodile::Totodile()
    :Agua("Totodile","Croconaw","Feraligatr"){
}
Totodile::Totodile(const Totodile& other)
    :Agua(other){
}
Totodile::~Totodile(){
}

Movida Totodile::hiddenSkill(int efectividad){
    Movida sheerforce("sheerforce",-80*Pokemon::getFuerza()/396,0,50,efectividad);
	return sheerforce;
}
