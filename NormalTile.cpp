#include <iostream> //Biblioteca iostream
#include "NormalTile.h" //Se incluye el archivo NormalTile.h
//Se obtiene normal
int NormalTile:: getNormal(){
  return normal;
}
//CONSTRUCTOR, no recibe parametros
NormalTile::NormalTile(){
normal=0;
}
//CONSTRUCTOR, recibe 2 parametros
NormalTile::NormalTile(int position,char typ):Tile(position,typ){
normal=0;
}
//Se obtiene el tipo de casilla
char NormalTile::getType(){
  return type;
}
//Se establece el tipo de casilla
void NormalTile::setType(){
  type='N';
}
