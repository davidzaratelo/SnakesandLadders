#ifndef MANUAL_H_INCLUDED//Se define la Clase en caso de que no este definida
#define MANUAL_H_INCLUDED//Se define la clase.

#include <vector>//Se incluye la biblioteca de vectorcm

class Manual:public Game{//Se declara la clase Game y que su clase padre es Game.
private://No hay atributos, debido a que esta clase es el modo de juego Automatic.
public:
  Manual();//CONSTRUCTOR, no recibe parámetros
  void Move(int,int,int,int,int);//Método Move, el cual, realiza POLIMORFISMO, teniendo la misma firma que el método de la clase padre.
};
#endif
