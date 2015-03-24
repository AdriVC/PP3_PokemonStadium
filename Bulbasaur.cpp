#include "Grama.h"
#include "Bulbasaur.h"
#include "Movida.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Bulbasaur::Bulbasaur()
    :Grama("Bulbasaur","Ivysaur","Venosaur"){
}
Bulbasaur::Bulbasaur(const Bulbasaur& other)
	:Grama(other){
}
Bulbasaur::~Bulbasaur(){
}
string Bulbasaur::toString()const{
	stringstream ss;
    ss << Pokemon::getNombre() << "[Lv " << Pokemon::getNivel() << "]";
	return ss.str();
}
Movida Bulbasaur::hiddenSkill(int efectividad){
    Movida chlorophyll("chlorophyll",0,50*Pokemon::getVelocidad()/396,80,efectividad);
	return chlorophyll;
}
