#include <iostream> //Biblioteca iostream
#include "Tile.h" //Se incluye el archivo Tile.h
#ifndef LADERTILE_H_INCLUDED  //Se define la clase en caso de no ser definida
#define LADDETILE_H_INCLUDED //Se define la clase

class LadderTile:public Tile{ //Se establece la clase LadderTile, que hereda los atributos y métodos de la clase Tile
private: //Atributos, con modificador de acceso privado
  int reward; //El atributo reward contiene la recompensa en caso de que el jugador esté en una casilla Snake.
public:
  LadderTile(); //CONSTRUCTOR, no recibe parametros
  LadderTile(int,char);// CONSTRUCTOR, recibe 2 parametros
  LadderTile(int);
  int getReward(); //Se obtiene reward
  void setReward(int);//Se establece reward
  char getType(); //Se obtiene el tipo de casilla
  void setType(); //Se obtiene el tipo de casilla
};
#endif
