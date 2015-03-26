#ifndef JUGADOR_H
#define JUGADOR_H

#include "Pokemon.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class Jugador{
    string nombre,sprite;
    int spritePos,totalPokemon,batallasGanadas,batallasPerdidas;
    vector<Pokemon*> pokedex;
public:
    Jugador(string,int);
    Jugador(const Jugador&);
    ~Jugador();
    string toString()const;
    string getNombre()const;
    string getSprite()const;
    int getTotalPokemon()const;
    int getBatallasGanadas()const;
    int getBatallasPerdidas()const;
    int getSpriteNum()const;
    void addPokemon(Pokemon*);
    void setNombre(string);
    void setSprite(int);
    void addBatallaGanada();
    void addBatallaPerdida();
    vector<Pokemon*> getPokedex()const;
};

#endif // JUGADOR_H
