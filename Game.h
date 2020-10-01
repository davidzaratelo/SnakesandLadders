#ifndef GAME_H_INCLUDED //Se define la clase en caso de no ser definida
#define GAME_H_INCLUDED //Se define la clase
#include <iostream>//Biblioteca iostream
#include<vector> //Biblioteca de vector
#include "Player.cpp"//Se incluye el archivo Player.cpp
#include "Dice.cpp"//Se incluye el archivo Dice.cpp
#include "Tile.cpp"//Se incluye el archivo Tile.cpp
#include "SnakeTile.cpp" //Se incluye el archivo SnakeTile.cpp
#include "LadderTile.cpp"//Se incluye el archivo LadderTile.cpp
#include "NormalTile.cpp" //Se incluye el archivo NormalTile.cpp
#include "Turn.cpp"

class Game{
protected://Atributos protegidos, para que las clases hijas accedan a sus atributos.
  vector<Player> player;
  Dice d1;// Se crea el dado 1 como atrubuto del Juego
  vector <Tile> tiles; //Vector de casillas, el cual será el tablero
public:
  void StablishPlayers(int); //Se establecen los jugadores
  void StablishBoard(int,int,int,int,int); //Se establece el tablero
  int getPenalty();//Obtiene penalty
  int getReward();//Obtiene reward
  Dice getDice();//Se obtiene el objeto d1
  Game();//CONSTRUCTOR, no recibe parametros
  int ReceivePenalty(int);//Se establece el penalty proporcionado por el usuario
  int ReceiveReward(int); //Se establece el reward proporcionado por el usuario
  int setTurnlimit(int); //Se establece el limite de turnos, proporcionado por el usuario
  int getTurnlimit();//Se obtiene el limite de turnos
  int CurrentPosition(int,int);//Se obtiene la posicion actual del jugador
  int TurnCheck(int);//Se obtiene el turno actual del jugador
  virtual void Move(int,int,int,int,int)=0;//Se establece el metodo Move, el cual realiza POLIMORFISMO con la instruccion virtual.
  int FinishGame();//Se finaliza el juego


};
#endif
