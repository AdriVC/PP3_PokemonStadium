#include "Pokemon.h"
#include "Grama.h"
#include "Movida.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Grama::Grama(string ev1, string ev2, string ev3)
    :Pokemon(ev1, ev2, ev3,"Fuego","Agua"){
}
Grama::Grama(const Grama& other)
	:Pokemon(other){
}
Grama::~Grama(){
}

string Grama::getClass()const{
    return "Grama";
}

Movida Grama::attack(int efectividad){
    Movida razorLeaf("razor leaf",-55*Pokemon::getVelocidad()/396,0,95,efectividad);
    return razorLeaf;
}
Movida Grama::defend(int efectividad){
    Movida leechSeed("leech seed",Pokemon::getHp()*Pokemon::getResistencia()/-396,Pokemon::getHp()*Pokemon::getResistencia()/396,90,efectividad);
	return leechSeed;
}
