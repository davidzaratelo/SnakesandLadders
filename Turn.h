//Se define la Clase en caso de que no este definida
#ifndef TURN_H_INCLUDED
//Se define la clase.
#define TURN_H_INCLUDED
#include <iostream> //Biblioteca iostream
using namespace std;

class Turn{ //Se crea la clase Turn
private: //Los atributos de la clase serán los variables que se desean imprimir en la consola.
int turn; //turno del jugador
int playernumber; //numero de jugador
int currposition; //posicion actual
int rolldice; //numero que arroja el dado
char tiletype; //tipo de casilla
int finalpos; //posicion final, es decir, la casilla después de cada incremento del dado
public:
Turn(); //CONSTRUCTOR, no recibe parametros
Turn(int,int,int,int,char,int); //CONSTRUCTOR, RECIBE 6 paramtros, los cuales serán los datos de cada turno del juego
friend ostream& operator<<(ostream& os, const Turn& t1);  //Se crea una funcion amiga, con la cual se realizará la sobrecarga del operador <<


};

ostream& operator<<(ostream& os,const Turn& t1) //la funcion amiga no se encuentra dentro de la clase y tiene como parametros de entrada ostream y un objeto Turn.
{
  //Dentro de esta sobrecarga del operador se imprimirá la informacion de cada jugador, turno por turno.
    os << t1.turn << " " << t1.playernumber <<" " << t1.currposition<<" "<<t1.rolldice<<" " << t1.tiletype<<" "<<t1.finalpos;
    return os;
}


#endif
