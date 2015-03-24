#include "Movida.h"
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
using std::rand;
using std::srand;
using std::time;
using std::string;
using std::stringstream;

Movida::Movida(string nombre, int poder, int ayuda, int certeza, double efectividad)
	:nombre(nombre),poder(poder), ayuda(ayuda), certeza(certeza),efectividad(efectividad){
    srand(time(0));
    random = rand()%100;
}
Movida::Movida(const Movida&  other)
	:nombre(other.nombre),poder(other.poder), ayuda(other.ayuda), certeza(other.certeza),efectividad(other.efectividad){
}
Movida::~Movida(){
}
string Movida::toString()const{
	stringstream ss;
	ss << " uso " << nombre;
    if(this->getGolpe() == 0)
		 ss << " pero fallo";
	else {
		if(efectividad == 0.5)
            ss << " y fue poco efectivo, con un effecto de " << this->getGolpe() << " al HP del oponente";
		else if(efectividad == 1)
            ss << " y fue efectivo, con un effecto de " << this->getGolpe() << " al HP del oponente";
		else if(efectividad == 2)
            ss << " y fue super efectivo, con un effecto de " << this->getGolpe() << " al HP del oponente";
		else
            ss << "con un effecto de " << this->getGolpe() << " al HP del oponente";
	}
    if(this->getAyuda() !=0)
        ss << "con un effecto de " << this->getAyuda() << " a si mismo";
	return ss.str();
}
string Movida::getNombre()const{
	return nombre;
}
int Movida::getGolpe()const{
    if( random < (100 - certeza))
		return 0;
	else
		return poder*efectividad;
}
int Movida::getAyuda()const{
		return ayuda*efectividad;
}
