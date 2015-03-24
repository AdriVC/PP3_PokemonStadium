#ifndef JUGADOR_H
#define JUGADOR_H

#include "Pokemon.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Jugador{
    string nombre,sprite;
    bool femenino;
    int spritePos;
    vector<Pokemon*> pokedex;
public:
    Jugador(string,bool,int);
    Jugador(const Jugador&);
    ~Jugador();
    string toString()const;
    string getNombre()const;
    string getSprite()const;
    bool getFemenino()const;
    void addPokemon(Pokemon*);
    void setNombre(string);
    void setSprite(int);
    void setFemenino(bool,int);
    vector<Pokemon*> getPokedex()const;
};

#endif // JUGADOR_H
