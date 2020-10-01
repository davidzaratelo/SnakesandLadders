#ifndef PLAYER_H_INCLUDED //Se define la Clase en caso de que no este
#define PLAYER_H_INCLUDED //Se define la clase.
#include <iostream>

class Player{
private: //Los atributos de la clase Player se establecen, siendo privados.
  int playernum;  //Numero de jugador
  int turn;  //Turno del jugador
  int tilepos;  //Posicion del jugador
public:  //Métodos de la clase

int getPlayerNum(); //Se obtiene el numero del jugador
void setPlayerNum(int); //Establece el numero de jugador
int getTurn();  //Se obtiene el turno
void setTurn(int); //Establece el turno
int getTilePos();  //Obtiene posicion del jugador en el tablero
void setTilePos(int);   //Establece la posicion del jugador
int CurrentTurn();  //Obtiene el turno actual del jugador
int UpdatePosition(int,int);  //Se actualiza la posicion del jugador
Player(int);  // CONSTRUCTOR, recibe un parámetro
Player();    //CONSTRUCTOR, no recibe parametros



};
#endif
