#include <iostream>
using namespace std;
#include "Manual.h"//Incluye el archivo Manual.h


Manual::Manual():Game(){//El Constructor recibe los atributos de la clase Game
}




void Manual:: Move(int i,int ntiles, int npenalty,int nreward,int turnlimit){//Método que describe las acciones realizadas por el programa en el modo Manual
  int roll,move,extra,currpos,turncounter,update,finish,limit,turn;
  char answer;
  int condition=1;
  int correct;
  char position;
  int counter=1;
  bool aux=true;
while (condition==1) {//Se obtiene la respuesta del usuario, en caso de que quiera continuar o finalizar el juego.
  do{
  try{
    cin>>answer;
    aux=true;
    if(answer=='C') {
      correct=1;
      condition=2;
    }
    if (answer=='E') {
      cout<<"Thanks for playing!!!"<<endl;
      correct=2;
      player[i].setTurn(turnlimit);
      condition=2;
    }
    if (answer!='C' && answer!='E' ) {
    throw "Invalid option, please press C to continue next turn or E to end the game";
    }
  }catch (const char* msg) {
    aux=false;
    cin.clear();
    string tmp;
    getline(cin, tmp);
    counter++;
       cerr << msg << endl;
         if (counter>5){
          cout<<"Invalid menu choice exceeded"<<endl;
          cout<<"--GAME OVER--"<<endl;
          exit(1);
         }
  }
}while(aux==false || counter>5);




}
roll=d1.Roll();//Se obtiene un numero aleatorio del dado del juego.
move=roll+player[i].getTilePos();//La variable move almacena el movimiento que realiza el jugador en el turno
position=tiles[move-1].getType();//Se obtiene la letra del tipo de casilla
currpos=move-roll;//Posicion actual del jugador
turn=player[i].CurrentTurn();//Turno actual del jugador

if (correct==1 && move<ntiles && turnlimit>=turn) {//Si el movimiento del jugador es menor al numero de casillas total y no excede el limite de turnos, el juego sigue.
  if (move<ntiles && turnlimit>=turn){
       if (position=='N'){
        Turn t1(turn,player[i].getPlayerNum(),currpos,roll,position,player[i].UpdatePosition(roll,ntiles));
        cout<<t1<<endl;
       }
      if (position=='S') {
      SnakeTile snake(npenalty);
      SnakeTile snake2;
      snake2=snake+move;
      move=move-ReceivePenalty(npenalty);
      Turn t2(turn,player[i].getPlayerNum(),currpos,roll,position,snake2.getPenalty());
      cout<<t2<<endl;
      }
      if (position=='L') {
      move=move+ReceiveReward(nreward);
      Turn t3(turn,player[i].getPlayerNum(),currpos,roll,position,player[i].UpdatePosition(roll+ReceiveReward(nreward),ntiles));
      cout<<t3<<endl;
      }
  }
}
if (correct==1 && move>=ntiles){//Si el movimiento total del jugador es mayor a la cantidad de casillas, el juego termina.
CurrentPosition(i,ntiles);
cout<<turn<<" "<<player[i].getPlayerNum()<<" "<<currpos<<" "<<roll<<" "<<" "<<" "<<player[i].UpdatePosition(roll,ntiles)<<endl;
cout<<"Player number "<<player[i].getPlayerNum()<<" is the winner!! " <<endl;
cout<<"GAME OVER"<<endl;
 }

 if (correct==1 && turnlimit<turn){//Si el turno actual es mayor a la cantidad limte de turnos, el juego termina.
 cout<<"The maximum number of turns has been reached.."<<endl;
 cout<<"GAME OVER"<<endl;
  }

}
