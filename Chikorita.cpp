#include "Grama.h"
#include "Chikorita.h"
#include "Movida.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Chikorita::Chikorita()
    :Grama("Chikorita","Bayleef","Meganium"){
}
Chikorita::Chikorita(const Chikorita& other)
	:Grama(other){
}
Chikorita::~Chikorita(){
}
string Chikorita::toString()const{
	stringstream ss;
    ss << Pokemon::getNombre() << "[Lv " << Pokemon::getNivel() << "]";
	return ss.str();
}
Movida Chikorita::hiddenSkill(int efectividad){
    Movida leafguard("leafguard",0,40*Pokemon::getFuerza()/396,80,efectividad);
	return leafguard;
}
