//Se define la Clase en caso de que no este definida
#ifndef AUTOMATIC_H_INCLUDED
//Se define la clase.
#define AUTOMATIC_H_INCLUDED
#include <vector>//Se incluye la biblioteca de vector

class Automatic:public Game{//Se declara la clase Automatic y que su clase padre es Game.
private://No hay atributos, debido a que esta clase es el modo de juego Automatic.
public:
  Automatic();//CONSTRUCTOR, no recibe parámetros
  void Move(int,int,int,int,int);//Método Move, el cual, realiza POLIMORFISMO, teniendo la misma firma que el método de la clase padre.
};
#endif
