#include "Pokemon.h"
#include "Agua.h"
#include "Movida.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Agua::Agua(string ev1, string ev2, string ev3)
    :Pokemon(ev1, ev2, ev3,"Grama","Fuego"){
}
Agua::Agua(const Agua& other)
	:Pokemon(other){
}
Agua::~Agua(){
}

string Agua::getClass()const{
    return "Agua";
}

Movida Agua::attack(int efectividad){
    Movida surf("surf",-90*Pokemon::getFuerza()/396,0,100,efectividad);
	return surf;
}
Movida Agua::defend(int efectividad){
    Movida aquaRing("aqua ring",0,Pokemon::getHp()*Pokemon::getResistencia()/396,90,efectividad);
	return aquaRing;
}
