#include "Fuego.h"
#include "Charmander.h"
#include "Movida.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Charmander::Charmander()
    :Fuego("Charmander","Charmeleon","Charizard"){
}
Charmander::Charmander(const Charmander& other)
	:Fuego(other){
}
Charmander::~Charmander(){
}

Movida Charmander::hiddenSkill(int efectividad){
    Movida solarPower("solar power",-60*Pokemon::getFuerza()/396,0,80,efectividad);
	return solarPower;
}
