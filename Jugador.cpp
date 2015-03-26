#include "Jugador.h"
#include "Pokemon.h"
#include <string>
#include <sstream>
#include <vector>
using std::string;
using std::stringstream;
using std::vector;

Jugador::Jugador(string nombre,int spritePos)
    :nombre(nombre),spritePos(spritePos),totalPokemon(0),batallasGanadas(0),batallasPerdidas(0){
    vector<Pokemon*> pokedex;
    this->setSprite(spritePos);
}

Jugador::Jugador(const Jugador& other)
    :nombre(other.nombre),sprite(other.sprite),spritePos(other.spritePos),totalPokemon(other.totalPokemon),
      batallasGanadas(other.batallasGanadas),batallasPerdidas(other.batallasPerdidas),pokedex(other.pokedex){
}

Jugador::~Jugador()
{
    for(int i=0; i<(int)this->pokedex.size(); i++){
        delete this->pokedex[i];
    }
}

string Jugador::toString()const{
    stringstream ss;
    ss << nombre << " [" << this->pokedex.size() << "]";
    return ss.str();
}

string Jugador::getNombre()const{
    return nombre;
}

string Jugador::getSprite()const{
    return sprite;
}

int Jugador::getSpriteNum()const{
    return spritePos;
}

int Jugador::getTotalPokemon()const{
    return totalPokemon;
}

int Jugador::getBatallasGanadas()const{
    return batallasGanadas;
}

int Jugador::getBatallasPerdidas()const{
    return batallasPerdidas;
}

void Jugador::setNombre(string nombre){
    this->nombre = nombre;
}

void Jugador::addPokemon(Pokemon* nuevo){
    pokedex.push_back(nuevo);
    totalPokemon++;
}

void Jugador::setSprite(int spritePos){
    this->spritePos = spritePos;
    stringstream ss;
        ss << ":/Sprites/Player" << spritePos << ".png";
    this->sprite = ss.str();
}

void Jugador::addBatallaGanada(){
    batallasGanadas++;
}

void Jugador::addBatallaPerdida(){
    batallasPerdidas++;
}

vector<Pokemon*> Jugador::getPokedex()const{
    return pokedex;
}
