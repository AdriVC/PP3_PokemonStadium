#include "Pokemon.h"
#include "Movida.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using std::string;
using std::stringstream;
using std::srand;
using std::time;

Pokemon::Pokemon(string ev1, string ev2, string ev3, string debilidad, string ventaja)
    :debilidad(debilidad),ventaja(ventaja){
    this->nombres[0] = ev1;
    this->nombres[1] = ev2;
    this->nombres[2] = ev3;
	srand(time(0)); //? aqui va este random o en el main?
	this->nivel = 10+rand()%90;
	this->setNombre();
	this->setFuerza();
	this->setResistencia();
	this->setVelocidad();
	this->hp = (2+rand()%3)*nivel;
}
Pokemon::Pokemon(const Pokemon& other)
    :debilidad(other.debilidad),ventaja(other.ventaja),nivel(other.nivel),hp(other.hp){
    this->nombres[0] = other.nombres[0];
    this->nombres[1] = other.nombres[1];
    this->nombres[2] = other.nombres[2];
	this->setNombre();
	this->setFuerza();
	this->setResistencia();
	this->setVelocidad();
}
Pokemon::~Pokemon(){
}
Movida Pokemon::tackle(){
    Movida tackle("tackle",-50*velocidad/396,0,95,1);
	return tackle;
}
Movida Pokemon::curl(){
    Movida curl("curl",0,50*resistencia/396,95,1);
    return curl;
}
string Pokemon::getNombre()const{
	return nombre;
}
string Pokemon::getSprite()const{
	return sprite;
}
string Pokemon::getDebilidad()const{
	return debilidad;
}
string Pokemon::getVentaja()const{
	return ventaja;
}
int Pokemon::getNivel()const{
	return nivel;
}
int Pokemon::getFuerza()const{
	return fuerza;
}
int Pokemon::getResistencia()const{
	return resistencia;
}
int Pokemon::getVelocidad()const{
	return velocidad;
}
int Pokemon::getHp()const{
	return hp;
}
void Pokemon::setSprite(){
    stringstream ss;
    ss << ":/Sprites/" << nombre << ".png";
    this->sprite = ss.str();
}
void Pokemon::setNombre(){
	this->nombre = nombres[(nivel-10)/30];
	this->setSprite();
}
void Pokemon::setDebilidad(string){
	this->debilidad = debilidad;
}
void Pokemon::setVentaja(string){
	this->ventaja = ventaja;
}
void Pokemon::setNivel(double incremento){
    this->nivel= (int)((double)this->nivel*incremento);
    if(this->nivel >100 ){
        this->nivel = 100;
    }else if (this->nivel <10 ){
        this->nivel = 10;
    }
    this->setNombre();
	this->setFuerza();
	this->setResistencia();
	this->setVelocidad();
    this->setHp((int)((double)this->getHp())*(incremento-1.0));
}
void Pokemon::setFuerza(){
	fuerza = (2+rand()%3)*nivel;
} 
void Pokemon::setResistencia(){
	resistencia = (2+rand()%3)*nivel;
}
void Pokemon::setVelocidad(){
	velocidad = (2+rand()%3)*nivel;
}
void Pokemon::setHp(int hp){
    this->hp+=hp;
    if(this->hp > 500)
        this->hp = 500;
    if(this->hp < 0)
        this->hp = 0;
}
string Pokemon::toString()const{
	stringstream ss;
    ss << nombre << " [Lv" << nivel << " | Hp" << hp << "]";
	return ss.str();
}
