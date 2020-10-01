#include <iostream> //Biblioteca iostream
#include "LadderTile.h" //Se incluye el archivo LadderTile.h
//Se obtiene reward
int LadderTile:: getReward(){
  return reward;
}
//CONSTRUCTOR, sin parametros
LadderTile::LadderTile(){
reward=3;
}
LadderTile::LadderTile(int rew){
  reward=rew;
}
//CONSTRUCTOR con 2 parametros de entrada
LadderTile::LadderTile(int position,char typ):Tile(position,typ){
reward=3;
}
//Se obtiene la recompensa
void LadderTile::setReward(int rew){
  reward=rew;
}
//Se obtiene el tipo de casillas
char LadderTile:: getType(){
  return type;
}
//Se establece el tipo de casilla
void LadderTile:: setType(){
  type='L';
}
