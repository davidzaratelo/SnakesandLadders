#include "Game.h"
using namespace std;

 void Game::StablishPlayers(int number){//Se establecen todos los jugadores en el juego
   for (int i=0;i<number;i++){
     player.push_back(i);
     player[i].setPlayerNum(i+1);
     player[i].setTurn(0);
     player[i].setTilePos(1);
   }
 }

void Game::StablishBoard(int ntiles,int npenalty,int nsnake,int nladder,int nreward){//Se establece el tablero
  NormalTile n1;//Se crea un objeto NormalTile
  SnakeTile s1; // Se crea objeto SnakeTile
  LadderTile l1; //Se crea objeto LadderTile
  s1.setPenalty(ReceivePenalty(npenalty));//Se establece el penalty
  l1.setReward(ReceiveReward(nreward));//Se establece el reward
  int timesnake=nsnake;
  int timesladder=nladder-1;
  int x=(5+rand()%((ntiles+1)-5));//Se llena el tablero de casillas Normales
    for (int i = 0; i<ntiles; i++) {
        tiles.push_back(n1);
        n1.setType();
        tiles[i].setPosition(i+1);
        tiles[i].setType(n1.getType());
    }
   for (int i=4; i<ntiles; i++){//Se establecen las casillas Snake en el tablero
       x=(5+rand()%((ntiles+1)-5));
        if (timesnake>=0) {
          tiles[x]=s1;
          s1.setType();
          tiles[x].setType(s1.getType());
          timesnake--;
         }
    }
    while(timesladder>=0){//Se establecen las casillas Ladder en el tablero
        x=(5+rand()%((ntiles+1)-5));
        char compare;
        compare=tiles[x].getType();
             if (timesladder>=0 && compare!='S') {
               tiles[x]=l1;
               l1.setType();
               tiles[x].setType(l1.getType());
               timesladder--;
              }
     }

}

Dice Game:: getDice(){
  return d1;
}//Se obtiene el objeto d1


int Game::ReceivePenalty(int pen){//Se establece el penalty
  int penalty;
  penalty=pen;
  return penalty;
}
int Game::ReceiveReward(int rew){//Se establece el reward
  int reward;
  reward=rew;
  return reward;
}
int Game:: setTurnlimit(int turnlim) {//Se establece el limite de turnos
int turnlimit;
turnlimit=turnlim;
return turnlim;
}

Game::Game(){//CONSTRUCTOR, no recibe parametros
  vector <Player> player;
  vector <Tile> tiles;
  Dice d1;
}
int Game::FinishGame(){//Se finaliza el juego
  return 2;
}
int Game::CurrentPosition(int i,int ntiles){ //Se obtiene la posicion actual del jugador
  int x;
  x=player[i].UpdatePosition(0,ntiles);
  return x;
}
int Game:: TurnCheck(int i){//se comprueba el turno
  int y;
  y=player[i].getTurn();
  return y;
}


void Game:: Move(int i,int ntiles, int npenalty,int nreward,int turnlimit){//Método que describe las acciones realizadas por el programa y despliega la informacion del jugador
   int roll,move,extra,currpos,turncounter,update,finish,limit,turn;
   char position;
      roll=d1.Roll();//Se tira el dado
      move=roll+player[i].getTilePos();//Se obtiene el movimiento del jugador
      position=tiles[move-1].getType();//Se obtiene el tipo de casilla en la que se encuentra el jugador
      currpos=move-roll;//Se obtiene la posicion actual del jugador
      turn=player[i].CurrentTurn(); //Se obtiene el turno actual del jugador
      //Si el movimiento del jugador es menor al numero de casillas total y no excede el limite de turnos, el juego sigue.
        if (move<ntiles && turnlimit>=turn){
             if (position=='N'){ //Si la casilla es normal no recibe penalizacion y se muestra la informacion del jugador en el turno actual
            cout<<turn<<" "<<player[i].getPlayerNum()<<" "<<currpos<<" "<<roll<<" "<<position<<" "<<player[i].UpdatePosition(roll,ntiles)<<endl;
             }
            if (position=='S') { //Si la casilla es tipo serpiente recibe penalizacion y se muestra la informacion del jugador en el turno actual
            move=move-ReceivePenalty(npenalty);
            cout<<turn<<" "<<player[i].getPlayerNum()<<" "<<currpos<<" "<<roll<<" "<<position<<" "<<player[i].UpdatePosition(roll-ReceivePenalty(npenalty),ntiles)<<endl;
            }
            if (position=='L') {//Si la casilla es tipo escalera recibe recompensa y se muestra la informacion del jugador en el turno actual
            move=move+ReceiveReward(nreward);
            cout<<turn<<" "<<player[i].getPlayerNum()<<" "<<currpos<<" "<<roll<<" "<<position<<" "<<player[i].UpdatePosition(roll+ReceiveReward(nreward),ntiles)<<endl;
            }
        }
    if (move>=ntiles){//Si el movimiento total del jugador es mayor a la cantidad de casillas, el juego termina.
    CurrentPosition(i,ntiles);
    cout<<player[i].CurrentTurn()<<" "<<player[i].getPlayerNum()<<" "<<currpos<<" "<<roll<<" "<<" "<<" "<<player[i].UpdatePosition(roll,ntiles)<<endl;
    cout<<"Player number "<<player[i].getPlayerNum()<<" is the winner!! " <<endl;
    cout<<"GAME OVER"<<endl;
     }
     if (turnlimit<turn){//Si el turno actual es mayor a la cantidad limte de turnos, el juego termina.
     cout<<"The maximum number of turns has been reached.."<<endl;
     cout<<"GAME OVER"<<endl;
      }
}
