#include "Jugador.h"
#include "Pokemon.h"
#include <string>
#include <sstream>
#include <vector>
using std::string;
using std::stringstream;
using std::vector;

Jugador::Jugador(string nombre,bool femenino,int spritePos)
    :nombre(nombre),femenino(femenino),spritePos(spritePos){
    vector<Pokemon*> pokedex;
    this->setSprite(spritePos);
}

Jugador::Jugador(const Jugador& other)
    :nombre(other.nombre),sprite(other.sprite),femenino(other.femenino),spritePos(other.spritePos),pokedex(other.pokedex){

}

Jugador::~Jugador()
{
    for(int i=0; i< this->pokedex.size(); i++){
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

bool Jugador::getFemenino()const{
    return femenino;
}

void Jugador::setNombre(string nombre){
    this->nombre = nombre;
}

void Jugador::addPokemon(Pokemon* nuevo){
    pokedex.push_back(nuevo);
}

void Jugador::setSprite(int spritePos){
    this->spritePos = spritePos;
    stringstream ss;
    if(this->femenino)
        ss << ":/Sprites/Female" << spritePos << ".png";
    else
        ss << ":/Sprites/Male" << spritePos << ".png";
    this->sprite = ss.str();
}

void Jugador::setFemenino(bool femenino,int spritePos){
    this->femenino = femenino;
    this->setSprite(spritePos);
}

vector<Pokemon*> Jugador::getPokedex()const{
    return pokedex;
}
