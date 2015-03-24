#include "Agua.h"
#include "Squirtle.h"
#include "Movida.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Squirtle::Squirtle()
    :Agua("Squirtle","Wartortle","Blastoise"){
}
Squirtle::Squirtle(const Squirtle& other)
    :Agua(other){
}
Squirtle::~Squirtle(){
}
string Squirtle::toString()const{
	stringstream ss;
    ss << Pokemon::getNombre() << "[Lv " << Pokemon::getNivel() << "]";
	return ss.str();
}
Movida Squirtle::hiddenSkill(int efectividad){
    Movida rainDish("rain dish",0,40*Pokemon::getResistencia()/396,60,efectividad);
	return rainDish;
}
