#include "Player.h"

int Player:: getPlayerNum(){
  return playernum;
}
void Player:: setPlayerNum(int player){
  playernum=player;
}

int Player:: getTurn(){
  return turn;
}
void Player:: setTurn(int num){
  turn=num;
}
int Player:: getTilePos(){
  return tilepos;
}
void Player:: setTilePos(int num){
  tilepos=num;
}
//Constructor de la clase Player, recibe 1 parámetro
Player::Player(int play){
  playernum=play;
  turn=0;
  tilepos=1;
}
//Constructor de la clase Player, recibe 0 parámetros.
Player::Player(){
  playernum=1;
  turn=0;
  tilepos=1;
}
//Se Obtiene el turno actual del jugador
int Player:: CurrentTurn(){
  turn=turn+1;
  return turn;
}
//Método con el cual se actualiza la Posicion
int Player:: UpdatePosition(int roll,int ntiles){
  //Si la posicion del jugador se encuentra dentro de los limites de las casillas, se aumenta su posicion
  if (tilepos<=ntiles) {
    tilepos=tilepos+roll;
  }
  //Si la posicion del jugador es mayor al limite de las casillas, el jugador se quedará en la última casilla
  if (tilepos>ntiles) {
    tilepos=ntiles;
  }
  //Si la posicion del jugador es menor a la casilla #1, debido a alguna penalizacion, el jugador iniciará en la casilla #1
  if (tilepos<=0) {
    tilepos=1;
  }
  return tilepos;
}
