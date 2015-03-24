#ifndef POKEMON_H
#define POKEMON_H

#include "Movida.h"
#include <string>
using std::string;

class Pokemon{
	string nombres[3],nombre,debilidad,ventaja,sprite;
	int nivel, fuerza, resistencia, velocidad, hp;
public:
    Pokemon(string,string,string,string,string);
	Pokemon(const Pokemon&);
	~Pokemon();
    Movida tackle();
    Movida block();
	string getNombre()const;
    string getSprite()const;
	string getDebilidad()const;
	string getVentaja()const;
	int getNivel()const;
	int getFuerza()const;
	int getResistencia()const;
	int getVelocidad()const;
	int getHp()const;
    void setSprite();
	void setNombre();
	void setDebilidad(string);
	void setVentaja(string);
	void setNivel(int);
	void setFuerza();
	void setResistencia();
	void setVelocidad();
	void setHp(int);
	virtual string toString()const;
	virtual Movida attack(int)=0;
	virtual Movida defend(int)=0;
	virtual Movida hiddenSkill(int)=0;
};

#endif /*POKEMON_H*/
