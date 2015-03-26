#include "Pokemon.h"
#include "Fuego.h"
#include "Movida.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Fuego::Fuego(string ev1, string ev2, string ev3)
    :Pokemon(ev1, ev2, ev3,"Agua","Grama"){
}
Fuego::Fuego(const Fuego& other)
	:Pokemon(other){
}
Fuego::~Fuego(){
}

string Fuego::getClass()const{
    return "Fuego";
}

Movida Fuego::attack(int efectividad){
    Movida ember("ember",-40*Pokemon::getFuerza()/396,0,80,efectividad);
	return ember;
}
Movida Fuego::defend(int efectividad){
    Movida flameCharge("flame charge",0,80*Pokemon::getVelocidad()/396,100,efectividad);
	return flameCharge;
}
