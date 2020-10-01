#ifndef DICE_H_INCLUDED //Se define la clase en caso de que no sea definida
//Se define la clase
#define DICE_H_INCLUDED

#include <iostream>//Se incluye la biblioteca iostream

using namespace std;//Se utiliza namespace para utilizar cout y cin sin std::

class Dice{ //Se define la clase Dice
private: //La clase tiene como atributo privado los espacios proporcionados por el dado.
  int spaces;
public:
  int getSpaces(); //Se obtienen los espacios dados
  Dice(); //CONSTRUCTOR
  int Roll(); //Se "tira" el dado, es decir, se obtiene un numero random
  void print(); //Se imprime la cantidad de espacios por avanzar
};

#endif
