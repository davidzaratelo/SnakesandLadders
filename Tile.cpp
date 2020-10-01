#include "Tile.h" //Se incluye el archivo "Tile.h"

Tile::Tile(){ //CONSTRUCTOR
position=1;
type='N';
}
Tile::Tile(int pos,char typ){ //CONSTRUCTOR con parámetros
position=pos;
type=typ;
}
//Obtiene Posicion de casilla
int Tile::getPosition(){
return position;
}
//Se establece la posicion de casilla
void Tile::setPosition(int pos){
  position=pos;
}
//Obtiene Tipo de casila
char Tile:: getType(){
  return type;
}
//Se establece el tipo de casilla
void Tile::setType(char typ){
  type=typ;
}
