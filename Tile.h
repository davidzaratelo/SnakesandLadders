#ifndef TILE_H_INCLUDED  //Se define la clase en caso de que no este definida
#define TILE_H_INCLUDED //Se define la clase
#include <iostream> //Bliblioteca iostream

class Tile{ //Se define la clase Tile (Casilla)
protected: //Los atributos se establecen como protegidos, asi, sus clases hijas podrán accesar a sus atributos
  int position; //Posicion de la casilla
  char type; //Tipo de casilla
public: //Métodos de la clase
  Tile(); //CONSTRUCTOR, no recibe ningun parametro
  Tile(int,char); //CONSTRUCTOR, recibe 2 parametros
  int getPosition(); //Se obtiene la posicion de la casilla
  void setPosition(int); //Se establece la posicion de la casilla
  char getType(); //Se obtiene el tipo de casilla
  void setType(char); //Se establece el tipo de casilla
};
#endif
