#include "Fuego.h"
#include "Cyndaquil.h"
#include "Movida.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Cyndaquil::Cyndaquil()
    :Fuego("Cyndaquil","Quilava","Typhlosion"){
}
Cyndaquil::Cyndaquil(const Cyndaquil& other)
	:Fuego(other){
}
Cyndaquil::~Cyndaquil(){
}
string Cyndaquil::toString()const{
	stringstream ss;
    ss << Pokemon::getNombre() << "[Lv " << Pokemon::getNivel() << "]";
	return ss.str();
}
Movida Cyndaquil::hiddenSkill(int efectividad){
    Movida flashFire("flash fire",-90*Pokemon::getFuerza()/396,0,80,efectividad);
	return flashFire;
}
