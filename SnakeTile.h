#ifndef SNAKETILE_H_INCLUDED //Se define la clase en caso de no estar definida
#define SNAKETILE_H_INCLUDED //Se define la clase
#include "Tile.h" //Se incluye el archivo Tile.h
#include <iostream> //Biblioteca iostream

class SnakeTile:public Tile{ //Se establece la clase SnakeTile, que hereda los atributos y métodos de la clase Tile
private: //Atributo privado de la clase SnakeTile
  int penalty; //Penalty es la cantidad de espacios de penalizacion que elige el usuario en caso de estar en casilla Snake
public:
  SnakeTile(); //Constructor, no recibe parametros
  SnakeTile(int,char,int); //Constructor, recibe 2 parametros
  SnakeTile(int);
  int getPenalty(); //Obtiene penalty
  void setPenalty(int); //Establece el penalty, con un paramtro introducido por el usuario
  char getType();//Se obtiene el tipo de casilla
  void setType(); //Se establece el tipo de casillas
  //A continuación se muestra la declaración de un metodo para la sobrecarga del operador +
  SnakeTile operator+(int moves){
    SnakeTile final;//Se crea un objeto SnakeTile, el cual será retornado
    final.penalty=moves-this->penalty;//Se suma la casilla en la que se encuentra el jugador con la penalizacion
    if (final.penalty<=0) { //Si la suma es menor a 0, esta se establecerá en 1.
      final.penalty=1;
    }
    return final;
  }
};
#endif
