#include <iostream>//Biblioteca iostream
#include "SnakeTile.h" //Se incluye el archivo SnakeTile.h
//Se obtiene el penalty
int SnakeTile::getPenalty(){
  return penalty;
}
//Constructor que recibe 2 parametros
SnakeTile::SnakeTile(int position,char type,int penal):Tile(position,type){
  penalty=penal;
}
SnakeTile::SnakeTile(int penal){
  penalty=penal;
}
//Constructor, no recibe parametro
SnakeTile::SnakeTile(){
  penalty=-3;
}
//Se establece el penalty
void SnakeTile::setPenalty(int penal){
  penalty=penal;
}
//Se obtiene el tipo de casilla
char SnakeTile:: getType(){
  return type;
}
//Se establece el tipo de casilla
void SnakeTile:: setType(){
  type='S';
}
