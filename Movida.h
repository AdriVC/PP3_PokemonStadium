#ifndef MOVIDA_H
#define MOVIDA_H
#include <string>
using std::string;

class Movida{
	string nombre;
    int poder, ayuda,certeza,random;
    double efectividad;
    bool fallo;
public:
	Movida(string,int,int,int,double);
    Movida(Movida&);
	~Movida();
    string toString()const;
	string getNombre()const;
    int getGolpe()const;
	int getAyuda()const;
};

#endif /*MOVIDA_H*/
