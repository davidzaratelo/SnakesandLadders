#ifndef NORMALTILE_H_INCLUDED //Se define la clase en caso de no ser definida
#define NORMALTILE_H_INCLUDED //Se define la clase
#include "Tile.h" //Se incluye el archivo Tile.h
#include <iostream> //Biblioteca iostream

class NormalTile:public Tile{ //Se establece la clase NormalTile, que hereda los atributos y métodos de la clase Tile
private: //Atributos, con modificador de acceso privado
  int normal; //El atributo normal, indica que no hay recompensa ni penalizacion
public: //Metodos de la clase
  NormalTile(); //CONSTRUCTOR, no recibe parametros
  NormalTile(int,char); //CONSTRUCTOR, recibe 2 parametros de entrada
  int getNormal(); //Se obtiene el atrubuto normal
  char getType(); //Se obtiene el tipo de casilla
  void setType();//Se establece el tipo de casilla
};
#endif
